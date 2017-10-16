#include <iostream>
#include <fstream>
#include <string>

#include <utility>
#include <unordered_map>

#include <cmath>

/**
 * Returns the distance between the given points on earth, given as
 * pairs of coordinates in radians.  (This would be part of what
 * you wrote for Assignment #1; we do not duplicate that code here.)
 * 
 * @param from a pair of latitude (range +/-pi/2) and longitude (+/- pi)
 * @return the distance between them assuming a spherical earth
 */
double distance(std::pair<double, double> from,
		std::pair<double, double> to);

int main(int argc, char **argv)
{
  if (argc < 2)
    {
      std::cerr << "USAGE: " << argv[0] << " airports-file [code*]"
		<< std::endl;
      return 0;
    }

  // read airport location database (thanks, FAA!)
  std::unordered_map<std::string, std::pair<double, double>> locations;
  
  std::ifstream in(argv[1]);
  std::string code;
  double lat;
  double lon;

  while (in >> code >> lat >> lon)
    {
      locations[code] = std::make_pair(lat, lon);
    }

  // go over command line arguments
  double total = 0.0;
  for (int i = 3; i < argc; i++)
    {
      // check from location
      if (locations.count(argv[i - 1]) == 0)
	{
	  std::cerr << argv[0] << ": could not find " << argv[i - 1]
		    << std::endl;
	  return 1;
	}

      // check to location (yes, non-endpoint codes are checked twice:
      // once by the above check in one interation and one at this
      // point in the next)
      if (locations.count(argv[i]) == 0)
	{
	  std::cerr << argv[0] << ": could not find " << argv[i]
		    << std::endl;
	  return 1;
	}

      // look up coordinates of the current from and to airports
      std::pair<double, double> origin = locations[argv[i - 1]];
      std::pair<double, double> destination = locations[argv[i]];

      // add in the distance between them
      total += distance(origin, destination);
    }

  std::cout << total << std::endl;
}

double distance(std::pair<double, double> from,
                std::pair<double, double> to)
{
  // some of your code from Assignment #1 goes here!
  return 0.0;
}
