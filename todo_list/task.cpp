#include <string>
#include <iostream>

#include "task.h"

namespace todo
{
  Task::Task(const std::string& d, int t) : description(d)
  {
    estimatedTime = t;
    completed = false;
  }

  void Task::complete()
  {
    completed = true;
  }

  bool Task::isCompleted() const
  {
    return completed;
  }

  void Task::print(std::ostream& os) const
  {
    os << estimatedTime << " " << description;
  }

  int Task::time() const
  {
    return estimatedTime;
  }
  
}
