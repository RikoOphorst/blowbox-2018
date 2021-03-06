#include "core/memory/pointer_math.h"

namespace blowbox
{
  namespace core
  {
    //------------------------------------------------------------------------------------------------------
    size_t PointerMath::AlignDelta(void* ptr, size_t align)
    {
      size_t delta = align -
        ((reinterpret_cast<size_t>(ptr)) &
        (static_cast<size_t>(align - 1)));

      if (delta == align)
      {
        delta = 0;
      }

      return delta;
    }

    //------------------------------------------------------------------------------------------------------
    void* PointerMath::Offset(void* ptr, int64_t offset)
    {
      return reinterpret_cast<void*>(reinterpret_cast<intptr_t>(ptr) + offset);
    }
  }
}