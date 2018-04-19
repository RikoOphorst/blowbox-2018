#pragma once

#include <qapplication.h>

namespace blowbox
{
  namespace engine
  {
    class Engine;
  }

  namespace editor
  {
    class MainWindow;

    /**
    * @brief Controls the Editor runtime.
    *
    * Under the hood this class manages both the engine::Engine instance
    * and the editor::MainWindow. Call Run() to initialize the editor and
    * call Shutdown() to shutdown the engine. Be sure to pass in the CLI
    * arguments into the Editor constructor, although it's not required.
    *
    */
    class Editor
    {
    public:
      /**
      * @brief Constructs the Editor.
      * @param[in] argc The CLI argument count.
      * @param[in] argv The CLI argument values.
      */
      Editor(int argc = 0, char** argv = nullptr);

      /**
      * @brief Destructs the Editor.
      */
      ~Editor();

      /**
      * @brief Runs the Editor.
      * @remarks This starts both the Engine and the MainWindow UI.
      */
      void Run();

      /**
      * @brief Shuts down the Editor.
      */
      void Shutdown();

    private:
      /**
      * @brief The OnInitialize function.
      */
      void OnInitialize();

      /**
      * @brief The OnBeginFrame function.
      */
      void OnBeginFrame();

      /**
      * @brief The OnPreUpdate function.
      */
      void OnPreUpdate();

      /**
      * @brief The OnUpdate function.
      */
      void OnUpdate();

      /**
      * @brief The OnFixedUpdate function.
      */
      void OnFixedUpdate();

      /**
      * @brief The OnPostUpdate function.
      */
      void OnPostUpdate();

      /**
      * @brief The OnPreRender function.
      */
      void OnPreRender();

      /**
      * @brief The OnRender function.
      */
      void OnRender();

      /**
      * @brief The OnPostRender function.
      */
      void OnPostRender();

      /**
      * @brief The OnEndFrame function.
      */
      void OnEndFrame();

      /**
      * @brief The OnShutdown function.
      */
      void OnShutdown();

      /**
      * @brief The OnInitialize function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the editor::Editor.
      */
      static void OnInitializeFn(void* userdata);

      /**
      * @brief The OnBeginFrame function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the editor::Editor.
      */
      static void OnBeginFrameFn(void* userdata);

      /**
      * @brief The OnPreUpdate function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the editor::Editor.
      */
      static void OnPreUpdateFn(void* userdata);

      /**
      * @brief The OnUpdate function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the editor::Editor.
      */
      static void OnUpdateFn(void* userdata);

      /**
      * @brief The OnFixedUpdate function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the editor::Editor.
      */
      static void OnFixedUpdateFn(void* userdata);

      /**
      * @brief The OnPostUpdate function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the editor::Editor.
      */
      static void OnPostUpdateFn(void* userdata);

      /**
      * @brief The OnPreRender function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the editor::Editor.
      */
      static void OnPreRenderFn(void* userdata);

      /**
      * @brief The OnRender function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the editor::Editor.
      */
      static void OnRenderFn(void* userdata);

      /**
      * @brief The OnPostRender function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the editor::Editor.
      */
      static void OnPostRenderFn(void* userdata);

      /**
      * @brief The OnEndFrame function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the editor::Editor.
      */
      static void OnEndFrameFn(void* userdata);

      /**
      * @brief The OnShutdown function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the editor::Editor.
      */
      static void OnShutdownFn(void* userdata);

    private:
      engine::Engine* engine_; //!< The engine::Engine instance is stored here.
      MainWindow* main_window_; //!< The editor::MainWindow instance is stored here.
      QApplication app_; //!< The QApplication instance of the Editor.
    };
  }
}