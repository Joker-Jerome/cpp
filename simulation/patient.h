#ifndef __PATIENT_H__
#define __PATIENT_H__

namespace cs427_527
{
  class Predator;
  class Prey;
  class Food;
  class Scent;

  class Patient
  {
  public:
    virtual ~Patient() {}
    virtual void acceptAction(const Predator& p) = 0;
    virtual void acceptAction(const Prey& p) = 0;
    virtual void acceptAction(const Food& f) = 0;
    virtual void acceptAction(const Scent& s) = 0;
  };

}
#endif
