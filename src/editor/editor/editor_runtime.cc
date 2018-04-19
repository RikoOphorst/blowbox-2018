#include "editor_runtime.h"

#include "editor/main_window.h"

#include <core/logger.h>
#include <core/memory/memory.h>
#include <engine/engine.h>

namespace blowbox
{
  namespace editor
  {
    //------------------------------------------------------------------------------------------------------
    EditorRuntime::EditorRuntime(int argc, char** argv) :
      app_(argc, argv)
    {
      engine_ = core::Memory::Construct<engine::Engine>(&core::Memory::default_allocator(), argc, argv);
      main_window_ = core::Memory::Construct<MainWindow>(&core::Memory::default_allocator(), &app_);

      engine_->SetCallbackUserdata(this);
      engine_->SetOnInitialize(OnInitializeFn);
      engine_->SetOnBeginFrame(OnBeginFrameFn);
      engine_->SetOnPreUpdate(OnPreUpdateFn);
      engine_->SetOnUpdate(OnUpdateFn);
      engine_->SetOnFixedUpdate(OnFixedUpdateFn);
      engine_->SetOnPostUpdate(OnPostRenderFn);
      engine_->SetOnPreRender(OnPreRenderFn);
      engine_->SetOnRender(OnRenderFn);
      engine_->SetOnPostRender(OnPostRenderFn);
      engine_->SetOnEndFrame(OnEndFrameFn);
      engine_->SetOnShutdown(OnShutdownFn);
    }

    //------------------------------------------------------------------------------------------------------
    EditorRuntime::~EditorRuntime()
    {
      core::Memory::Destruct(main_window_);
      core::Memory::Destruct(engine_);
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::Run()
    {
      engine_->Run();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::Shutdown()
    {
      engine_->Shutdown();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnInitialize()
    {
      main_window_->show();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnBeginFrame()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnPreUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnFixedUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnPostUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnPreRender()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnRender()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnPostRender()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnEndFrame()
    {
      app_.processEvents();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnShutdown()
    {
      
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnInitializeFn(void* userdata)
    {
      EditorRuntime* editor = reinterpret_cast<EditorRuntime*>(userdata);
      editor->OnInitialize();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnBeginFrameFn(void* userdata)
    {
      EditorRuntime* editor = reinterpret_cast<EditorRuntime*>(userdata);
      editor->OnBeginFrame();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnPreUpdateFn(void* userdata)
    {
      EditorRuntime* editor = reinterpret_cast<EditorRuntime*>(userdata);
      editor->OnPreUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnUpdateFn(void* userdata)
    {
      EditorRuntime* editor = reinterpret_cast<EditorRuntime*>(userdata);
      editor->OnUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnFixedUpdateFn(void* userdata)
    {
      EditorRuntime* editor = reinterpret_cast<EditorRuntime*>(userdata);
      editor->OnFixedUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnPostUpdateFn(void* userdata)
    {
      EditorRuntime* editor = reinterpret_cast<EditorRuntime*>(userdata);
      editor->OnPostUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnPreRenderFn(void* userdata)
    {
      EditorRuntime* editor = reinterpret_cast<EditorRuntime*>(userdata);
      editor->OnPreRender();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnRenderFn(void* userdata)
    {
      EditorRuntime* editor = reinterpret_cast<EditorRuntime*>(userdata);
      editor->OnRender();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnPostRenderFn(void* userdata)
    {
      EditorRuntime* editor = reinterpret_cast<EditorRuntime*>(userdata);
      editor->OnPostRender();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnEndFrameFn(void* userdata)
    {
      EditorRuntime* editor = reinterpret_cast<EditorRuntime*>(userdata);
      editor->OnEndFrame();
    }

    //------------------------------------------------------------------------------------------------------
    void EditorRuntime::OnShutdownFn(void* userdata)
    {
      EditorRuntime* editor = reinterpret_cast<EditorRuntime*>(userdata);
      editor->OnShutdown();
    }
  }
}