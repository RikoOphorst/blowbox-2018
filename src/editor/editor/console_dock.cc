#include "console_dock.h"

#include "core/logger.h"

#include <qapplication.h>
#include <qmainwindow.h>
#include <qdockwidget.h>
#include <qwidget.h>
#include <qboxlayout.h>
#include <qtextbrowser.h>
#include <qcheckbox.h>
#include <qplaintextedit.h>
#include <qsplitter.h>
#include <qcombobox.h>

namespace blowbox
{
  namespace editor
  {
    //------------------------------------------------------------------------------------------------------
    ConsoleDock::ConsoleDock(
      QWidget* contents,
      QComboBox* channels_filter,
      QCheckBox* logs_checkbox,
      QCheckBox* warnings_checkbox,
      QCheckBox* errors_checkbox,
      QTextBrowser* console_view,
      QTextEdit* console_input,
      QPushButton* submit_button
    ) :
      dock_contents_(contents),
      channels_filter_(channels_filter),
      logs_checkbox_(logs_checkbox),
      warnings_checkbox_(warnings_checkbox),
      errors_checkbox_(errors_checkbox),
      console_view_(console_view),
      console_input_(console_input),
      submit_button_(submit_button)
    {
      console_view_->setFont(QFont(QStringLiteral("Consolas"), 9, 400, false));

      core::Logger::message_receiver = &MessageReceiver;
      core::Logger::message_receiver_userdata = this;
    }

    //------------------------------------------------------------------------------------------------------
    ConsoleDock::~ConsoleDock()
    {
      
    }
    
    //------------------------------------------------------------------------------------------------------
    void ConsoleDock::MessageReceiver(void* userdata, const core::Message& message)
    {
      ConsoleDock* console_dock = reinterpret_cast<ConsoleDock*>(userdata);

      console_dock->ProcessMessage(message);
    }
    
    //------------------------------------------------------------------------------------------------------
    void ConsoleDock::ProcessMessage(const core::Message& message)
    {
      console_view_->append(QString(message.message));
    }
  }
}