#include "core.h"

namespace blowbox
{
  namespace core
  {
    Core* Core::instance_ = nullptr;

    //------------------------------------------------------------------------------------------------------
    Core::Core(int argc, char** argv)
    {
      if (instance_ != nullptr)
      {
        // throw assert
        return;
      }
      else
      {
        instance_ = this;
      }
    }

    //------------------------------------------------------------------------------------------------------
    Core::~Core()
    {

    }

    //------------------------------------------------------------------------------------------------------
    Core* Core::Instance()
    {
      return instance_;
    }
  }
}