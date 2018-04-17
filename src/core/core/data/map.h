#pragma once

#include "core/memory/allocators/eastl_allocator.h"
#include <EASTL/map.h>

namespace blowbox
{
  template<typename Key, typename T, typename Compare = eastl::less<Key>, typename Allocator = core::EASTLAllocator>
  using Map = eastl::map<Key, T, Compare, Allocator>;
}