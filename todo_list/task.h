#ifndef __TASK_H__
#define __TASK_H__

#include <string>
#include <iostream>

namespace todo
{

  class Task
  {
  public:
    /**
     * Creates an uncompleted task with the given description and
     * estimated completion time.
     *
     * @param d a string
     * @param t a positive integer
     */
    Task(const std::string& d, int t);
    
    /**
     * Marks this task as completed.
     */
    void complete();
    
    /**
     * Reports whether this task has been completed.
     *
     * @return true if and only if this task has been completed
     */
    bool isCompleted() const;
    
    /**
     * Outputs a printable representation of this task to the given
     * stream.
     *
     * @param os a stream
     */
    void print(std::ostream& os) const;

    /**
     * Returns the estimated time for this task.
     *
     * @return the estimated time
     */
    int time() const;
    
  private:
    std::string description;
    int estimatedTime;
    bool completed;
  };

}
    
#endif
