#pragma once

#include "core/memory/allocators/eastl_allocator.h"
#include <EASTL/unordered_map.h>

namespace blowbox
{
  template<typename Key, typename T, typename Hash = eastl::hash<Key>, typename Predicate = eastl::equal_to<Key>, typename Allocator = core::EASTLAllocator>
  using UnorderedMap = eastl::unordered_map<Key, T, Hash, Predicate, Allocator>;
}