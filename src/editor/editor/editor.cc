#include "editor.h"

#include "editor/main_window.h"

#include <core/logger.h>
#include <core/memory/memory.h>
#include <engine/engine.h>

namespace blowbox
{
  namespace editor
  {
    //------------------------------------------------------------------------------------------------------
    Editor::Editor(int argc, char** argv) :
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
    Editor::~Editor()
    {
      core::Memory::Destruct(main_window_);
      core::Memory::Destruct(engine_);
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::Run()
    {
      engine_->Run();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::Shutdown()
    {
      engine_->Shutdown();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnInitialize()
    {
      main_window_->show();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnBeginFrame()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnPreUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnFixedUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnPostUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnPreRender()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnRender()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnPostRender()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnEndFrame()
    {
      app_.processEvents();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnShutdown()
    {
      
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnInitializeFn(void* userdata)
    {
      Editor* editor = reinterpret_cast<Editor*>(userdata);
      editor->OnInitialize();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnBeginFrameFn(void* userdata)
    {
      Editor* editor = reinterpret_cast<Editor*>(userdata);
      editor->OnBeginFrame();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnPreUpdateFn(void* userdata)
    {
      Editor* editor = reinterpret_cast<Editor*>(userdata);
      editor->OnPreUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnUpdateFn(void* userdata)
    {
      Editor* editor = reinterpret_cast<Editor*>(userdata);
      editor->OnUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnFixedUpdateFn(void* userdata)
    {
      Editor* editor = reinterpret_cast<Editor*>(userdata);
      editor->OnFixedUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnPostUpdateFn(void* userdata)
    {
      Editor* editor = reinterpret_cast<Editor*>(userdata);
      editor->OnPostUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnPreRenderFn(void* userdata)
    {
      Editor* editor = reinterpret_cast<Editor*>(userdata);
      editor->OnPreRender();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnRenderFn(void* userdata)
    {
      Editor* editor = reinterpret_cast<Editor*>(userdata);
      editor->OnRender();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnPostRenderFn(void* userdata)
    {
      Editor* editor = reinterpret_cast<Editor*>(userdata);
      editor->OnPostRender();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnEndFrameFn(void* userdata)
    {
      Editor* editor = reinterpret_cast<Editor*>(userdata);
      editor->OnEndFrame();
    }

    //------------------------------------------------------------------------------------------------------
    void Editor::OnShutdownFn(void* userdata)
    {
      Editor* editor = reinterpret_cast<Editor*>(userdata);
      editor->OnShutdown();
    }
  }
}