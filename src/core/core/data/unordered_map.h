#pragma once

#include "core/memory/allocators/eastl_allocator.h"
#include <EASTL/unordered_map.h>

namespace blowbox
{
  /**
  * @brief An unordered map, based on eastl::map.
  * @tparam Key The key of the map.
  * @tparam T The value of the map.
  * @tparam Hash Function to use when hashing Keys. Defaults to eastl::hash<Key>.
  * @tparam Predicate Predicate func. Defaults to eastl::equal_to<Key>.
  * @tparam Allocator The allocator to use for the map. Default to core::EASTLAllocator.
  */
  template<typename Key, typename T, typename Hash = eastl::hash<Key>, typename Predicate = eastl::equal_to<Key>, typename Allocator = core::EASTLAllocator>
  using UnorderedMap = eastl::unordered_map<Key, T, Hash, Predicate, Allocator>;
}