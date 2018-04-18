#pragma once

#include "core/memory/allocators/eastl_allocator.h"
#include <EASTL/queue.h>

namespace blowbox
{
  /**
  * @brief Queue data structure, maps to eastl::queue.
  * @tparam T The type of the value to store in the queue.
  * @tparam Allocator Allocator to use. Defaults to core::EASTLAllocator.
  */
  template<typename T, typename Allocator = core::EASTLAllocator>
  using Queue = eastl::queue<T, eastl::deque<T, Allocator>>;
}