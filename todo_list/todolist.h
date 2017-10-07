#ifndef __TODO_LIST_H__
#define __TODO_LIST_H__

#include "task.h"

namespace todo
{

  class ToDoList
  {
  public:
    /**
     * Creates an empty to-do list.
     */
    ToDoList();

    /**
     * Creates a copy of the given to-do list.
     *
     * @param orig a to-do list
     */
    ToDoList(const ToDoList &toCopy);

    /**
     * Moves the data from the given to-do list to the newly created one.
     * The given list is left in a valid but arbitrary state.
     *
     * @param orig a to-do list
     */
    ToDoList(ToDoList&& toMove);

    /**
     * Destroys a to-do list.
     */
    ~ToDoList();
    
    /**
     * Adds the given task to the end of this to-do list.
     *
     * @param t a task
     * @return this to-do list
     */
    ToDoList& add(const Task& t);

    /**
     * Determines if there are uncompleted tasks on this list.
     *
     * @return true if and only if there are uncompleted tasks
     */
    bool isIncomplete() const;

    /**
     * Returns the next task on this to-do list.
     *
     * @return the next task on this to-do list
     */
    Task getNext() const;

    /**
     * Marks the next task on this to-do list as complete and moves it to the
     * end of this list's completed tasks list.
     */
    void completeNext();

    /**
     * Exchanges the next two incomplete items on this to-do list.  No
     * effect if there are fewer than two incomplete items.
     */
    void delayNext();

    /**
     * Moves the next incomplete task on this to-do list to the end.
     * No effect if this to-do list is empty.
     */
    void postponeNext();

    /**
     * Returns the total time remaining of all the uncompleted tasks on the
     * list.
     *
     * @return the total time remaining of all the uncompleted tasks.
     */
    int timeRemaining() const;

    /**
     * Returns the number of remaining uncompleted tasks on this list.
     *
     * @return the number of remaining uncompleted tasks
     */
    int remainingTasks() const;

    /**
     * Makes this list a copy of the given list.
     *
     * @param rhs a to-do list
     * @return this list
     */
    ToDoList& operator=(const ToDoList& rhs);

    /**
     * Moves the data from the given list into this list.
     * The given list is left in a valid but arbitrary state.
     *
     * @param rhs a to-do list
     * @return this list
     */
    ToDoList& operator=(ToDoList&& rhs);
    
  private:
    void embiggen();
    void deallocate(Task *t);
    
    static const int DEFAULT_CAPACITY = 2;
    Task *list;
    int listCapacity;
    int completedCount;
    int totalCount;
  };

}


#endif
