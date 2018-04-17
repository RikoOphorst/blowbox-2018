#include "editor/main_window.h"

#include "core/logger.h"

#include <QtWidgets/qapplication.h>

using namespace blowbox;

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  editor::MainWindow* window = new editor::MainWindow(&app);

  for (int i = 0; i < 100; i++)
  {
    core::Logger::Log(core::MessageSource::Editor, "This is a log");
    core::Logger::Warn(core::MessageSource::Editor, "This is a warning");
    core::Logger::Error(core::MessageSource::Editor, "This is a error");
  }

  window->show();

  return app.exec();
}