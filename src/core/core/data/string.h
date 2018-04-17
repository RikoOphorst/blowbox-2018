#pragma once

#include "core/memory/allocators/eastl_allocator.h"
#include <EASTL/string.h>

namespace blowbox
{
  using String = eastl::basic_string<char, core::EASTLAllocator>;
  using WString = eastl::basic_string<wchar_t, core::EASTLAllocator>;
}