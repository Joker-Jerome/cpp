#include <iostream>

#include "task.h"
#include "todolist.h"

namespace todo
{

  ToDoList::ToDoList()
  {
    completedCount = 0;
    totalCount = 0;
    listCapacity = DEFAULT_CAPACITY;
    list = (Task *)::operator new(sizeof(Task) * DEFAULT_CAPACITY);
  }

  ToDoList::ToDoList(const ToDoList &toCopy)
  {
    // copy primitive values from list to copy from
    completedCount = toCopy.completedCount;
    totalCount = toCopy.totalCount;

    // calculate size of new array, giving it some room for more tasks
    listCapacity = (totalCount >= DEFAULT_CAPACITY) ? totalCount * 2 : DEFAULT_CAPACITY;

    // deep copy of the array in the list to copy from
    list = (Task *)::operator new(listCapacity * sizeof(Task));
    for (int i = 0; i < totalCount; i++)
      {
	new (list + i)Task(toCopy.list[i]);
      }
  }

  ToDoList::ToDoList(ToDoList &&toMove)
  {
    // shallow copy of array in the list to move from
    completedCount = toMove.completedCount;
    totalCount = toMove.totalCount;
    listCapacity = toMove.listCapacity;
    list = toMove.list;

    // zero out list we moved from
    toMove.completedCount = 0;
    toMove.totalCount = 0;
    toMove.listCapacity = 0;
    toMove.list = NULL;
  }
  
  ToDoList::~ToDoList()
  {
    deallocate(list);
  }

  void ToDoList::deallocate(Task *l)
  {
      for (int i = 0; i < totalCount; i++)
      {
	l[i].~Task();
      }
      ::operator delete(l);
  }

  
  ToDoList& ToDoList::operator=(const ToDoList &rhs)
  {
    // check for self-assignment
    if (&rhs != this)
      {
	// free old array
	deallocate(list);
	
	// copy primitive values from list to assign from
	completedCount = rhs.completedCount;
	totalCount = rhs.totalCount;

	// calculate size of new array, giving it some room for more tasks
	listCapacity = (totalCount >= DEFAULT_CAPACITY) ? totalCount * 2 : DEFAULT_CAPACITY;

	// deep copy of the array in the list to copy from
	list = (Task *)::operator new(sizeof(Task) * listCapacity);
	for (int i = 0; i < totalCount; i++)
	  {
	    new (list + i)Task(rhs.list[i]);
	  }
      }
    return *this;
  }

  ToDoList& ToDoList::operator=(ToDoList &&rhs)
  {
    // check for self-assignment
    if (&rhs != this)
      {
	// free old array
	deallocate(list);
	
	// shallow copy of array in the list to move from
	completedCount = rhs.completedCount;
	totalCount = rhs.totalCount;
	listCapacity = rhs.listCapacity;
	list = rhs.list;

	// zero out list we moved from
	rhs.completedCount = 0;
	rhs.totalCount = 0;
	rhs.listCapacity = 0;
	rhs.list = nullptr;
      }
    return *this;
  }

  ToDoList& ToDoList::add(const Task& t)
  {
    // check for resize
    if (totalCount == listCapacity)
      {
	embiggen();
      }

    // add item at after current last item
    new (list + totalCount)Task(t);
    totalCount++;

    return *this;
  }

  /**
   * Enlarges the array that holds this list's tasks.
   */
  void ToDoList::embiggen()
  {
    // remember old list
    Task *old = list;

    // calculate new size (resizing by constant factor is important here
    // for efficiency)
    int biggerSize = (listCapacity * 2 > DEFAULT_CAPACITY) ? listCapacity * 2 : DEFAULT_CAPACITY;

    // make new, bigger array and copy items into it
    list = (Task *)::operator new(biggerSize * sizeof(Task));
    for (int i = 0; i < totalCount; i++)
      {
	new (list + i)Task(std::move(old[i]));
      }
    listCapacity = biggerSize;

    // free old array
    deallocate(old);
  }
  
  bool ToDoList::isIncomplete() const
  {
    return (completedCount < totalCount);
  }

  Task ToDoList::getNext() const
  {
    if (completedCount < totalCount)
      {
	return list[completedCount];
      }
    else
      {
	throw std::string("called ToDoList::getNext on completed list");
      }
  }

  void ToDoList::completeNext()
  {
    if (completedCount < totalCount)
      {
	list[completedCount].complete();
	completedCount++;
      }
  }

  void ToDoList::delayNext()
  {
    if (totalCount - completedCount >= 2)
      {
	Task delayed = list[completedCount];
	list[completedCount] = list[completedCount + 1];
	list[completedCount + 1] = delayed;
      }
  }

  void ToDoList::postponeNext()
  {
    if (totalCount - completedCount >= 2)
      {
	Task postponed = list[completedCount];
	for (int i = completedCount; i < totalCount - 1; i++)
	  {
	    list[i] = list[i + 1];
	  }
	list[totalCount - 1] = postponed;
      }
  }

  int ToDoList::timeRemaining() const
  {
    int tot = 0;

    for (int i = completedCount; i < totalCount; i++)
      {
	tot += list[i].time();
      }

    return tot;
  }
  
  int ToDoList::remainingTasks() const
  {
    return totalCount - completedCount;
  }

  
}
