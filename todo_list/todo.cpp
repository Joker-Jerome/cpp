#include <iostream>
#include <sstream>

#include "task.h"
#include "todolist.h"

int main()
{
  std::cout << "Enter tasks; blank line to end" << std::endl;

  todo::ToDoList todo;

  std::string input;
  while (std::getline(std::cin, input)
	 && input.length() > 0)
    {
      std::istringstream sin(input);

      int time;
      std::string description;
      if (sin >> time >> std::ws && std::getline(sin, description))
	{
	  todo::Task t(description, time);
	  todo.add(t);
	}
    }

  std::string command;
  while (todo.isIncomplete()
	 && (todo.getNext().print(std::cout), std::cout << std::endl)
	 && std::getline(std::cin, command)
	 && command.length() > 0)
    {
      if (command == "c")
	{
	  todo.completeNext();
	}
      else if (command == "d")
	{
	  todo.delayNext();
	}
      else if (command == "p")
	{
	  todo.postponeNext();
	}
    }

  if (!todo.isIncomplete())
    {
      std::cout << "Congratulations!  You've completed all of your tasks!"
		<< std::endl;
    }
  else
    {
      std::cout << todo.remainingTasks() << " tasks remain; estimated "
		<< todo.timeRemaining() << " minutes to complete"
		<< std::endl;
    }
  
}
