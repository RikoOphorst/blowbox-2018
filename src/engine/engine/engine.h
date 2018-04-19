#pragma once

#include <core/data/functional.h>

namespace blowbox
{
  namespace engine
  {
    /**
    * @brief Callback function type that describes the function called when the engine is initialized.
    */
    using CallbackOnInitialize  = eastl::function<void(void*)>; //!< Callback function type that describes the function called right after the systems in the engine are initialized.
    using CallbackOnBeginFrame  = eastl::function<void(void*)>; //!< Callback function type that describes the function called when the engine begins a frame.
    using CallbackOnPreUpdate   = eastl::function<void(void*)>; //!< Callback function type that describes the function called right before all systems are updated.
    using CallbackOnUpdate      = eastl::function<void(void*)>; //!< Callback function type that describes the function called when the engine updates all systems.
    using CallbackOnFixedUpdate = eastl::function<void(void*)>; //!< Callback function type that describes the function called at a fixed time step (e.g. 60 times per second) to update systems in the engine.
    using CallbackOnPostUpdate  = eastl::function<void(void*)>; //!< Callback function type that describes the function called right after all systems have been updated, including the fixed update.
    using CallbackOnPreRender   = eastl::function<void(void*)>; //!< Callback function type that describes the function called right before all systems are rendered.
    using CallbackOnRender      = eastl::function<void(void*)>; //!< Callback function type that describes the function called when the engine renders all systems.
    using CallbackOnPostRender  = eastl::function<void(void*)>; //!< Callback function type that describes the function called right after all systems have been rendered but not presented to the screen.
    using CallbackOnEndFrame    = eastl::function<void(void*)>; //!< Callback function type that describes the function called when the engine ends a frame.
    using CallbackOnShutdown    = eastl::function<void(void*)>; //!< Callback function type that describes the function called right before the systems in the engine are shutdown.

    /**
    * @brief The class that initializes & manages all systems in the engine and also controls the game loop.
    *
    * If you want to boot the blowbox engine, you should create an instance of
    * this class. To run the engine, you should call Run(). To shutdown the engine,
    * you should call Shutdown(). If you want to add custom logic to certain events
    * that happen throughout the lifetime of the engine, you can set callback
    * functions using any of the SetOn* functions. If you want to supply any custom
    * data to any of these callback functions, you can set a custom void* to some
    * sort of userdata object you would like to pass along to all of your callbacks.
    *
    * @remarks Only one instance of the Engine can be alive at the same time.
    * @remarks You can easily retrieve the current instance of the engine via Engine::Instance().
    */
    class Engine
    {
    public:
      /**
      * @brief Constructs the Engine. Does not run it immediately.
      * @param[in] argc The number of command line arguments.
      * @param[in] argv A char* array of command line arguments values.
      */
      Engine(int argc = 0, char** argv = nullptr);
      
      /**
      * @brief Destructs the Engine. 
      * @remarks You should have called Shutdown() before destructing the Engine instance if the engine was running.
      */
      ~Engine();

      /**
      * @brief Retrieves the instance of the Engine.
      * @remarks This functions asserts when there is no instance of the engine alive.
      */
      static Engine& Instance();

      /**
      * @brief Initializes all the systems in the engine and starts running the gameloop.
      * @remarks This function is blocking.
      * @remarks You can set callbacks for specific events that happen during Engine runtime by using the various Engine::SetOn* functions.
      * @remarks You can set a custom userdata pointer by calling Engine::SetCalllbackUserdata() which gets sent to every callback.
      * @remarks You should set all your callbacks before calling Engine::Run(), although it is possible to modify them later on during engine runtime.
      */
      void Run();

      /**
      * @brief Shuts down the entire engine as soon as it has finished the current frame.
      */
      void Shutdown();

    public:
      /**
      * @brief Sets the userdata that gets passed into every callback.
      * @param[in] userdata A pointer that can point to anything you want.
      */
      void SetCallbackUserdata(void* userdata);

      /** @return Returns the userdata pointer. */
      void* GetCallbackUserdata() const;

      /** 
      * @brief Sets the OnInitialize callback.
      * @param[in] callback The callback to be called.
      * @remarks Callback gets called right after all systems are initialized.
      */
      void SetOnInitialize(const CallbackOnInitialize& callback);

      /** @returns The OnInitialize callback. */
      const CallbackOnInitialize& GetOnInitialize() const;

      /**
      * @brief Sets the OnBeginFrame callback.
      * @param[in] callback The callback to be called.
      * @remarks Callback gets called at the very start of a frame.
      */
      void SetOnBeginFrame(const CallbackOnBeginFrame& callback);

      /** @returns The OnBeginFrame callback. */
      const CallbackOnBeginFrame& GetOnBeginFrame() const;

      /**
      * @brief Sets the OnPreUpdate callback.
      * @param[in] callback The callback to be called.
      * @remarks Callback gets called before the engine systems get updated.
      */
      void SetOnPreUpdate(const CallbackOnPreUpdate& callback);

      /** @returns The OnPreUpdate callback. */
      const CallbackOnPreUpdate& GetOnPreUpdate() const;

      /**
      * @brief Sets the OnUpdate callback.
      * @param[in] callback The callback to be called.
      * @remarks Callback gets called when the engine systems get updated.
      */
      void SetOnUpdate(const CallbackOnUpdate& callback);

      /** @returns The OnUpdate callback. */
      const CallbackOnUpdate& GetOnUpdate() const;

      /**
      * @brief Sets the OnFixedUpdate callback.
      * @param[in] callback The callback to be called.
      * @remarks Callback gets called a fixed amount of time per second.
      */
      void SetOnFixedUpdate(const CallbackOnFixedUpdate& callback);

      /** @returns The OnFixedUpdate callback. */
      const CallbackOnFixedUpdate& GetOnFixedUpdate() const;

      /**
      * @brief Sets the OnPostUpdate callback.
      * @param[in] callback The callback to be called.
      * @remarks Callback gets called right after the engine systems have been updated, including the fixed update.
      */
      void SetOnPostUpdate(const CallbackOnPostUpdate& callback);

      /** @returns The OnPostUpdate callback. */
      const CallbackOnPostUpdate& GetOnPostUpdate() const;

      /**
      * @brief Sets the OnPreRender callback.
      * @param[in] callback The callback to be called.
      * @remarks Callback gets called right before the engine systems get rendered.
      */
      void SetOnPreRender(const CallbackOnPreRender& callback);

      /** @returns The OnPreRender callback. */
      const CallbackOnPreRender& GetOnPreRender() const;

      /**
      * @brief Sets the OnRender callback.
      * @param[in] callback The callback to be called.
      * @remarks Callback gets called when the engine systems get rendered.
      */
      void SetOnRender(const CallbackOnRender& callback);

      /** @returns The OnRender callback. */
      const CallbackOnRender& GetOnRender() const;

      /**
      * @brief Sets the OnPostRender callback.
      * @param[in] callback The callback to be called.
      * @remarks Callback gets called right after the engine systems have been rendered, but not presented to the screen.
      */
      void SetOnPostRender(const CallbackOnPostRender& callback);

      /** @returns The OnPostRender callback. */
      const CallbackOnPostRender& GetOnPostRender() const;

      /**
      * @brief Sets the OnEndFrame callback.
      * @param[in] callback The callback to be called.
      * @remarks Callback gets called at the very end of a frame.
      */
      void SetOnEndFrame(const CallbackOnEndFrame& callback);

      /** @returns The OnEndFrame callback. */
      const CallbackOnEndFrame& GetOnEndFrame() const;

      /**
      * @brief Sets the OnShutdown callback.
      * @param[in] callback The callback to be called.
      * @remarks Callback gets called right before all the systems in the engine get shutdown.
      */
      void SetOnShutdown(const CallbackOnShutdown& callback);

      /** @returns The OnShutdown callback. */
      const CallbackOnShutdown& GetOnShutdown() const;

    private:
      bool is_running_; //!< Flag that defines whether the engine is currently running or not.

      void* callback_userdata_; //!< The custom user data pointer that gets passed into all callback functions.
      CallbackOnInitialize  callback_on_initialize_;    //!< The custom callback that gets called right after systems have been initialized.
      CallbackOnBeginFrame  callback_on_begin_frame_;   //!< The custom callback that gets called at the very beginning of every frame.
      CallbackOnPreUpdate   callback_on_pre_update_;    //!< The custom callback that gets called right before engine systems get updated.
      CallbackOnUpdate      callback_on_update_;        //!< The custom callback that gets called when engine systems are getting updated.
      CallbackOnFixedUpdate callback_on_fixed_update_;  //!< The custom callback that gets called at a fixed amount of times per second.
      CallbackOnPostUpdate  callback_on_post_update_;   //!< The custom callback that gets called right after engine systems have been updated, including fixed update.
      CallbackOnPreRender   callback_on_pre_render_;    //!< The custom callback that gets called right before the engine systems are rendered.
      CallbackOnRender      callback_on_render_;        //!< The custom callback that gets called when engine systems are getting rendered.
      CallbackOnPostRender  callback_on_post_render_;   //!< The custom callback that gets called after all systems have been rendered, but not presented to the screen.
      CallbackOnEndFrame    callback_on_end_frame_;     //!< The custom callback that gets called at the very end of a frame.
      CallbackOnShutdown    callback_on_shutdown_;      //!< The custom callback that gets called right before the systems in the engine are shutdown.

      static Engine* instance_; //!< The singleton instance of the Engine created by the Engine constructor.
    };
  }
}