#include "editor/main_window.h"

#include "core/logger.h"
#include "engine/engine.h"

#include <QtWidgets/qapplication.h>

using namespace blowbox;

struct AppData
{
  AppData(int argc, char** argv) : app(argc, argv) {}
  QApplication app;
};

void OnInitialize(void* userdata)
{
  AppData* app_data = reinterpret_cast<AppData*>(userdata);

  editor::MainWindow* window = new editor::MainWindow(&app_data->app);
  window->show();

  core::Logger::Assert(false, "release test");
}

void OnUpdate(void* userdata)
{
  //core::Logger::Log(core::MessageSource::Editor, "This is a log");
  //core::Logger::Warn(core::MessageSource::Editor, "This is a warning");
  //core::Logger::Error(core::MessageSource::Editor, "This is a error");
}

void OnEndFrame(void* userdata)
{
  AppData* app_data = reinterpret_cast<AppData*>(userdata);

  app_data->app.processEvents();
}

int main(int argc, char** argv)
{
  AppData app_data(argc, argv);

  engine::Engine blowbox_editor(argc, argv);
  
  blowbox_editor.SetCallbackUserdata(&app_data);
  blowbox_editor.SetOnInitialize(OnInitialize);
  blowbox_editor.SetOnUpdate(OnUpdate);
  blowbox_editor.SetOnEndFrame(OnEndFrame);
  
  blowbox_editor.Run();

  return 0;
}