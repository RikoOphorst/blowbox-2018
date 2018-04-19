#include "editor/editor.h"

#include <core/memory/memory.h>

using namespace blowbox;

int main(int argc, char** argv)
{
  editor::Editor* editor = core::Memory::Construct<editor::Editor>(&core::Memory::default_allocator(), argc, argv);

  editor->Run();

  core::Memory::Destruct(editor);

  return 0;
}