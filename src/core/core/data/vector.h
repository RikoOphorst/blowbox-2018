#pragma once

#include "core/memory/allocators/eastl_allocator.h"
#include <EASTL/vector.h>

namespace blowbox
{
  template<typename T, typename Allocator = core::EASTLAllocator>
  using Vector = eastl::vector<T, Allocator>;
}