#pragma once

#include "core/memory/allocators/eastl_allocator.h"
#include <EASTL/vector.h>

namespace blowbox
{
  /**
  * @brief Vector data structure, maps to eastl::vector.
  * @tparam T The type of the value to store in the queue.
  * @tparam Allocator Allocator to use. Defaults to core::EASTLAllocator.
  */
  template<typename T, typename Allocator = core::EASTLAllocator>
  using Vector = eastl::vector<T, Allocator>;
}