#include <vector>
#include <string>
#include <sstream>

#include "merlin.h"

namespace cs427_527
{

Merlin::Merlin()
  : board(DEFAULT_SIZE, std::vector<bool>(DEFAULT_SIZE, false))
{
  moveCount = 0;
}

  Merlin::Merlin(const std::string& s)
  {
    throw std::string("initializeation from string not supported");
  }

  Merlin::Merlin(std::istream& is)
  : board(DEFAULT_SIZE, std::vector<bool>(DEFAULT_SIZE, false))

{
  moveCount = 0;
  
  for (unsigned int i = 0; i < board.size(); i++)
    {
      std::string line;
      std::getline(is, line);
      for (unsigned int j = 0; j < board[i].size() && j < line.length(); j++)
	{
	  board[i][j] = (line[j] == '*');
	}
    }
}

bool Merlin::isLegalMove(const std::string& move) const
{
  if (move.length() != 2)
    {
      return false;
    }

  unsigned int row = move[0] - 'A';
  if (row > board.size())
    {
      return false;
    }

  unsigned int col = move[1] - '1';
  if (col > board[0].size())
    {
      return false;
    }

  return true;
}

void Merlin::makeMove(const std::string& move)
{
  if (isLegalMove(move))
    {
      unsigned int row = move[0] - 'A';
      unsigned int col = move[1] - '1';
      
      if (row == board.size() / 2 && col == board[row].size() / 2)
	{
	  // middle; do union of middle row and column
	  for (unsigned int r = 0; r < board.size(); r++)
	    {
	      board[r][col] = !board[r][col];
	    }
	  for (unsigned int c = 0; c < board[row].size(); c++)
	    {
	      if (c != board[row].size() / 2) // skip middle
		{
		  board[row][c] = !board[row][c];
		}
	    }
	}
      else if ((row + col) % 2 == 0)
	{
	  // corner
	  int center = board.size() / 2;
	  board[row][col] = !board[row][col];
	  board[row][center] = !board[row][center];
	  board[center][col] = !board[center][col];
	  board[center][center] = !board[center][center];

	}
      else
	{
	  // middle of edge
	  unsigned int row1, row2, col1, col2;
	  if (row == 0 || row == board.size() - 1)
	    {
	      row1 = row2 = row;
	      col1 = 0;
	      col2 = board[0].size() - 1;
	    }
	  else
	    {
	      row1 = 0;
	      row2 = board.size() - 1;
	      col1 = col2 = col;
	    }

	  for (unsigned int r = row1; r <= row2; r++)
	    {
	      for (unsigned int c = col1; c <= col2; c++)
		{
		  board[r][c] = !board[r][c];
		}
	    }
	}
    }

  moveCount++;
}

int Merlin::totalMoves() const
{
  return moveCount;
}

bool Merlin::isSolved() const
{
  unsigned int count = 0;
  for (auto i = board.begin(); i != board.end(); i++)
    {
      for (auto j = (*i).begin(); j != (*i).end(); j++)
	{
	  count += (*j ? 1 : 0);
	}
    }

  return count == board.size() * board[0].size();
}

std::string Merlin::toString() const
{
  std::ostringstream out;
  
  for (auto i = board.begin(); i != board.end(); i++)
    {
      for (auto j = (*i).begin(); j != (*i).end(); j++)
	{
	  out << (*j ? '*' : '.');
	}
      out << std::endl;
    }

  return out.str();
}

std::ostream& operator<<(std::ostream& os, const Merlin& m)
{
  return os << m.toString();
}

  
}
