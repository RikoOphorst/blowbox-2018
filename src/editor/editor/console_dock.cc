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

#include <ctime>

namespace blowbox
{
  namespace editor
  {
    //------------------------------------------------------------------------------------------------------
    ConsoleDock::ConsoleDock(
      QWidget* contents,
      QTextBrowser* console_view,
      QTextEdit* console_input,
      QPushButton* submit_button
    ) :
      dock_contents_(contents),
      console_view_(console_view),
      console_input_(console_input),
      submit_button_(submit_button)
    {
      console_view_->setFont(QFont(QStringLiteral("Consolas"), 8, 800, false));

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
      String full_message = "[";

      ParseTimeStamp(message.time_stamp, &full_message);

      full_message += "] ";
      full_message += message.message;
      full_message += "\n";

      QTextCursor cursor = console_view_->textCursor();
      cursor.setCharFormat(GetCharFormatByMessageType(message.type));
      cursor.insertText(QString(full_message.c_str()));
      cursor.movePosition(QTextCursor::End);
      
      console_view_->setTextCursor(cursor);
    }
    
    //------------------------------------------------------------------------------------------------------
    void ConsoleDock::ParseTimeStamp(const std::chrono::time_point<std::chrono::system_clock>& time, String* out_parsed_time)
    {
      std::time_t time_stamp = std::chrono::system_clock::to_time_t(time);

      tm time_tm;
      localtime_s(&time_tm, &time_stamp);

      auto FormatTime = [](int time_tm)
      {
        String formatted = std::to_string(time_tm).c_str();
        formatted = formatted.size() == 1 ? "0" + formatted : formatted;

        return formatted;
      };

      (*out_parsed_time) += FormatTime(time_tm.tm_hour) + ":" + FormatTime(time_tm.tm_min) + ":" + FormatTime(time_tm.tm_sec);
    }
    
    //------------------------------------------------------------------------------------------------------
    QTextCharFormat ConsoleDock::GetCharFormatByMessageType(const core::MessageType& type)
    {
      QTextCharFormat format;
      switch (type)
      {
      case core::MessageType::Log:
        break;
      case core::MessageType::Warning:
        format.setBackground(QBrush(QColor(140, 144, 0, 255)));
        format.setForeground(QBrush(QColor(0, 0, 0, 255)));
        break;
      case core::MessageType::Error:
        format.setBackground(QBrush(QColor(140, 23, 0, 255)));
        format.setForeground(QBrush(QColor(0, 0, 0, 255)));
        break;
      case core::MessageType::Assert:
        format.setBackground(QBrush(QColor(140, 23, 0, 255)));
        format.setForeground(QBrush(QColor(0, 0, 0, 255)));
        break;
      }

      return format;
    }
  }
}