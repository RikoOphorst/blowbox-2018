#pragma once

#include "core/data/string.h"

#include <qdockwidget.h>

class QWidget;
class QBoxLayout;
class QTextBrowser;
class QCheckBox;
class QTextEdit;
class QSplitter;
class QComboBox;
class QPushButton;
class QTextCharFormat;

namespace blowbox
{


  namespace core
  {
    enum class MessageType;
    struct Message;
  }

  namespace editor
  {
    class ConsoleDock
    {
    public:
      ConsoleDock(
        QWidget* contents,
        QTextBrowser* console_view,
        QTextEdit* console_input,
        QPushButton* submit_button
      );
      ~ConsoleDock();

    private:
      static void MessageReceiver(void* user_data, const core::Message& message);

      void ProcessMessage(const core::Message& message);

      void ParseTimeStamp(const std::chrono::time_point<std::chrono::system_clock>& time, String* out_parsed_time);

      QTextCharFormat GetCharFormatByMessageType(const core::MessageType& type);

    private:
      QWidget* dock_contents_;
      QTextBrowser* console_view_;

      QTextEdit* console_input_;
      QPushButton* submit_button_;
    };
  }
}