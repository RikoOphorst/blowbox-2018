#pragma once

#include <EASTL/functional.h>

namespace blowbox
{
  /**
  * @brief Executes an eastl::function safely by checking whether it is set before it is called.
  * @tparam T The EASTL function you want to call, e.g. eastl::function<void(int)>
  * @tparam Args Variadic number of arguments that will be passed in directly to the function call.
  */
  template<typename T, typename ... Args>
  inline void ExecuteCallbackSafely(const T& callback, Args&&... arguments)
  {
    if (callback)
    {
      callback(arguments...);
    }
  }
}