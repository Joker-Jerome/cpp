#include <iostream>
#include <string>

#include "todolist.h"
#include "task.h"

using todo::Task;
using todo::ToDoList;

ToDoList morningList(const std::string&);

int main(int argc, char *argv[])
{
  Task coffee("make coffee", 10);
  Task drink("drink coffee", 30);
  Task walk("walk to office", 20);
  Task prep("prepare for class", 60);
  Task teach("teach class", 75);

  std::cout << "Making Monday" << std::endl;
  ToDoList monday;
  monday.add(coffee).add(drink);

  std::cout << "Making Wednesday" << std::endl;
  // = in initialization is not assignment; it passes rhs to constructor --
  // the copy constructor in this case since monday is an lvalue
  ToDoList wednesday = monday;
  wednesday.add(walk).add(prep).add(teach);

  std::cout << "Making Thursday" << std::endl;
  // g++ in this case elides one call to the move constructor, bypassing
  // the temporary created as the return value from morningList
  // (compilers may optionally elide copy/move constructors)
  ToDoList thursday = morningList("tea");
  //ToDoList thursday(morningList("tea")); // equivalent

  std::cout << "Making Friday" << std::endl;
  // the below uses copy constructor for friday since add returns an lvalue
  ToDoList friday = morningList("tea").add(Task("make more tea", 5));

  std::cout << "Copying Monday" << std::endl;
  // move assignment since morning list returns a rvalue
  monday = morningList("coffee");
}

ToDoList morningList(const std::string& drink)
{
  ToDoList tea;
  tea.add(Task("make tea", 10)).add(Task("drink tea", 30));

  ToDoList coffee;
  coffee.add(Task("make coffee", 10)).add(Task("drink coffee", 30));

  if (drink == "tea")
    {
      return tea;
    }
  else
    {
      return coffee;
    }
}
