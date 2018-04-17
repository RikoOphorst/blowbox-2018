#pragma once

#include "core/memory/allocators/eastl_allocator.h"
#include <EASTL/queue.h>

namespace blowbox
{
  template<typename T, typename Allocator = core::EASTLAllocator>
  using Queue = eastl::queue<T, eastl::deque<T, Allocator>>;
}