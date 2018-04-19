#pragma once

namespace blowbox
{
  namespace engine
  {
    class Engine;
  }

  namespace client
  {
    class MainWindow;

    /**
    * @brief Controls the ClientRuntime.
    *
    * Under the hood this class manages the engine::Engine instance Call Run() 
    * to initialize the client and call Shutdown() to shutdown the engine. Be 
    * sure to pass in the CLI arguments into the ClientRuntime constructor, 
    * although it's not required.
    */
    class ClientRuntime
    {
    public:
      /**
      * @brief Constructs the ClientRuntime.
      * @param[in] argc The CLI argument count.
      * @param[in] argv The CLI argument values.
      */
      ClientRuntime(int argc = 0, char** argv = nullptr);

      /**
      * @brief Destructs the ClientRuntime.
      */
      ~ClientRuntime();

      /**
      * @brief Runs the ClientRuntime.
      */
      void Run();

      /**
      * @brief Shuts down the ClientRuntime.
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
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the client::ClientRuntime.
      */
      static void OnInitializeFn(void* userdata);

      /**
      * @brief The OnBeginFrame function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the client::ClientRuntime.
      */
      static void OnBeginFrameFn(void* userdata);

      /**
      * @brief The OnPreUpdate function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the client::ClientRuntime.
      */
      static void OnPreUpdateFn(void* userdata);

      /**
      * @brief The OnUpdate function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the client::ClientRuntime.
      */
      static void OnUpdateFn(void* userdata);

      /**
      * @brief The OnFixedUpdate function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the client::ClientRuntime.
      */
      static void OnFixedUpdateFn(void* userdata);

      /**
      * @brief The OnPostUpdate function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the client::ClientRuntime.
      */
      static void OnPostUpdateFn(void* userdata);

      /**
      * @brief The OnPreRender function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the client::ClientRuntime.
      */
      static void OnPreRenderFn(void* userdata);

      /**
      * @brief The OnRender function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the client::ClientRuntime.
      */
      static void OnRenderFn(void* userdata);

      /**
      * @brief The OnPostRender function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the client::ClientRuntime.
      */
      static void OnPostRenderFn(void* userdata);

      /**
      * @brief The OnEndFrame function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the client::ClientRuntime.
      */
      static void OnEndFrameFn(void* userdata);

      /**
      * @brief The OnShutdown function that will be set on the core::Engine.
      * @param[in] userdata The custom userdata pointer we set, which is a pointer to the instance of the client::ClientRuntime.
      */
      static void OnShutdownFn(void* userdata);

    private:
      engine::Engine* engine_; //!< The engine::Engine instance is stored here.
    };
  }
}