#include "iservice.h"

namespace blowbox
{
  namespace engine
  {
    //------------------------------------------------------------------------------------------------------
    IServiceBase::IServiceBase(const String& string) :
      name_(name_)
    {

    }

    //------------------------------------------------------------------------------------------------------
    IServiceBase::~IServiceBase()
    {

    }
    
    //------------------------------------------------------------------------------------------------------
    const String& IServiceBase::GetName() const
    {
      return name_;
    }

    //------------------------------------------------------------------------------------------------------
    size_t IServiceBase::GetNewID()
    {
      static size_t id = 0;
      return id++;
    }
  }
}