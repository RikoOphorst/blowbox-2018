#include "editor/editor_runtime.h"

#include <core/memory/memory.h>

using namespace blowbox;

int main(int argc, char** argv)
{
  editor::EditorRuntime editor(argc, argv);

  editor.Run();

  return 0;
}