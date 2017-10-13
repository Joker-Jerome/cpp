#include <iostream>
#include <fstream>

#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

/**
 * Processes US DOT commercial aviation data to determine
 * which airports are least connected to the commercial aviation
 * system as measured by the average number of flights needed
 * to travel to and from each airport.
 *
 * Data comes in two files: one containing the flights taken by
 * passengers on each trip
 *
 * 201446290 1 4 4 CAK PHL - 16 1.00 X
 * 201443910 4 4 4 CLT BTR X 16 1.00 X
 * 201442610 1 4 4 BHM CLT - 16 2.00 X
 * 201442610 3 4 4 LGA CLT - US 2.00 X
 * 201442610 2 4 4 CLT LGA X US 2.00 X
 * 201442610 4 4 4 CLT BHM X YV 2.00 X
 * 20144895 2 5 4 CLT EWR - US 1.00 X
 * 201445959 1 4 4 CAK DCA - 16 1.00 X
 * 201448083 2 4 4 CLT MIA X US 1.00 X
 * 201444998 4 4 4 CLT CAK X US 1.00 X
 * 201442453 4 4 4 CLT BHM X 16 1.00 X
 * 201443809 3 4 4 LGA DFW - AA 1.00 X
 * 201449893 4 4 4 CLT CLE X US 1.00 X
 * 201446669 1 3 4 CHA CLT - 16 1.00 X
 * 201443000 2 4 4 CLT PIT X US 1.00 X
 *
 * (for example, trip 201442610 had 2 passengers travelling
 * from Birmingham, AL to New York-La Guardia and back via Charlotte:
 * BHM-CLT-LGA-CLT-BHM)
 *
 * and another file containing fares
 *
 * 201444772 CAK EYW 279.00 394.00
 * 201444531 CAK CLT 266.00 394.00
 * 2014419906 DAY MHT 198.48 477.00
 * 201442610 BHM LGA 165.00 350.00
 * 201442610 LGA BHM 165.00 544.00
 * 2014419918 DAY MHT 179.00 477.00
 * 2014410666 BHM CLT 313.87 350.00
 * 201448381 SFO CHO 287.50 2521.00
 *
 * (for example, the passengers on the above trip paid $165 to
 * travel to LaGuardua and $165 to travel back).
 */



// STL doesn't provide output operators (<<) for containers (which allows
// us to use them with elements that don't themselves overload <<).
// But there is a nice package for printing containers available at
// http://louisdx.github.io/cxx-prettyprint/
#include "prettyprint.hpp"

// a record from the coupon file is a tuple
// (id, origin, destination, sequece-number, total-records-in-sequence, number-of-passengers)
using coupon = std::tuple<std::string, std::string, std::string, int, int, int>;

// a record from the market file is a tuple (id, origin, destination)
using segment = std::tuple<std::string, std::string, std::string>;

// so we can refer to components of tuples by name rather than index
using fields = enum {ID, ORIGIN, DESTINATION, SEQ, TOT, PAX};

// a trip is a sequence of airports and a number of passengers
using trip = std::pair<std::vector<std::string>, int>;

// we maintain a map from ids to trips
using trips = std::unordered_map<std::string, trip>;

// we also maintain a map from airports to (total-segments, total-trips)
// pairs
using counter = std::unordered_map<std::string, std::pair<int, int>>;

// Reads one record frmo the coupon file.
coupon readCoupon(std::istream& in);

// Reads one record from the market file
segment readSegment(std::istream& in);

// Updates a map containing the segment and trip count for the given
// airport, adding the values to the existing values if the airport
// is already present, and creating a new entry if not.
void updateCounts(counter& counts, std::string airport, int n, int x);

int main(int argc, char **argv)
{
  if (argc < 3)
    {
      std::cerr << "USAGE: " << argv[0] << " coupon-file market-file"
		<< std::endl;
      return 0;
    }

  // open the files for reading
  std::ifstream couponsIn(argv[1]);
  std::ifstream marketIn(argv[2]);
  
  trips t;

  // read from coupon file until we can't read any more
  coupon c;
  while (c = readCoupon(couponsIn), couponsIn)
    {
      std::string id = std::get<ID>(c);
      if (t.count(id) == 0)
	{
	  // id hasn't been seen -- we know the number of airports
	  // in the trip from the total-records-in-sequence field
	  // and can make a vector exactly long enough to hold the
	  // airports we'll find later
	  std::vector<std::string> route(std::get<TOT>(c) + 1,
					 std::string());
	  t[id] = std::make_pair(route, std::get<PAX>(c));
	}

      // get the existing record from the map
      trip& trip = t[id];

      // update the vector stored in that record
      trip.first[std::get<SEQ>(c) - 1] = std::get<ORIGIN>(c);
      trip.first[std::get<SEQ>(c)] = std::get<DESTINATION>(c);
    }

  // create the map from airports to trip and segment totals
  counter counts;

  // read from the market file until we can't read any more
  segment s;
  while (s = readSegment(marketIn), marketIn)
    {
      // get the origin, destination and id from the tuple we just read
      const std::string& origin = std::get<ORIGIN>(s);
      const std::string& destination = std::get<DESTINATION>(s);

      std::string id = std::get<ID>(s);
      
      if (t.count(id) > 0)
	{
	  // we have a record for this id -- retrieve it
	  trip& trip = t[id];

	  // unpack the route and passenger count
	  std::vector<std::string>& route = trip.first;
	  int n = trip.second;

	  // find the first occurrence of the origin airport we
	  // just read from the market data and the first occurrence
	  // of the destination airport after that
	  // (this isn't perfect, but this is the easiest thing to
	  // do and works around 99% of the time)
	  // for example, if the route is
	  // BHM-CLT-AGS-ORD-CLT-PHL-BDL
	  // and the fares used were BHM-AGS, AGS-CLT, and CLT-BDL
	  // then we match those with BHM-CLT-AGS, AGS-ORD-CLT,
	  // and CLT-PHL-BDL

	  auto start = std::find(route.begin(), route.end(), origin);
	  auto end = std::find(start, route.end(), destination);
	  
	  if (start != route.end() && end != route.end())
	    {
	      // found a matching part of the route;
	      // update the counts for the origin and destination
	      // airports
	      updateCounts(counts, origin, n, n * (end - start));
	      updateCounts(counts, destination, n, n * (end - start));

	      // remove the part of the route we just matched
	      route.erase(start + 1, end);
	    }
	  else
	    {
	      std::cerr << "error matching segments for id "
			<< std::get<ID>(s)
			<< std::endl;
	    }
	}
    }

  // prepare for final output by computing average number of segments
  // for each airport and putting (airport, average) into a vector
  // so we can sort
  std::vector<std::pair<std::string, double>> averageStops;
  for (auto i = counts.begin(); i != counts.end(); i++)
    {
      averageStops.push_back(std::make_pair((*i).first, (double)(*i).second.second / (*i).second.first));
    }

  // sort the vector by descending average
  std::sort(averageStops.begin(),
	    averageStops.end(),
	    [](std::pair<std::string, double> p1,
	       std::pair<std::string, double> p2)
	    {
	      return p1.second > p2.second;
	    });

  // output the vector (thank you, prettyprint!)
  std::cout << averageStops << std::endl;
}

coupon readCoupon(std::istream& in)
{
  std::string id;
  int seq;
  int tot;
  int q;
  std::string origin;
  std::string destination;
  char br;
  std::string airline;
  double pax;
  char cabin;

  in >> id >> seq >> tot >> q >> origin >> destination >> br >> airline >> pax >> cabin;

  return std::make_tuple(id, origin, destination, seq, tot, (int)pax);
}

segment readSegment(std::istream& in)
{
  std::string id;
  std::string origin;
  std::string destination;
  double fare;
  double distance;
  
  in >> id >> origin >> destination >> fare >> distance;

  return std::make_tuple(id, origin, destination);
}

void updateCounts(counter& counts, std::string airport, int n, int x)
{
  if (counts.count(airport) == 0)
    {
      counts[airport] = std::make_pair(n, x);
    }
  else
    {
      auto old = counts[airport];
      counts[airport] = std::make_pair(old.first + n, old.second + x);
    }
}
