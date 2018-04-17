#pragma once

#include <EASTL/functional.h>

#define BLOWBOX_CALL_FUNCTION_SAFELY(func, ...) if (func) { func(##__VA_ARGS__); }

namespace blowbox
{
  //------------------------------------------------------------------------------------------------------
  template<typename T, typename ... Args>
  inline void ExecuteCallbackSafely(const T& callback, Args&&... arguments)
  {
    if (callback)
    {
      callback(arguments...);
    }
  }
}