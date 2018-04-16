#pragma once

#include <qdockwidget.h>

class QWidget;
class QGridLayout;
class QTextBrowser;
class QCheckBox;
class QPlainTextEdit;

namespace blowbox
{
  namespace editor
  {
    class ConsoleDock : public QDockWidget
    {
    public:
      ConsoleDock(QMainWindow* main_window);
      ~ConsoleDock();

    private:
      QWidget* dock_contents_;
      QGridLayout* dock_layout_;
      QTextBrowser* console_view_;

      QCheckBox* show_logs_checkbox_;
      QCheckBox* show_warnings_checkbox_;
      QCheckBox* show_errors_checkbox_;

      QPlainTextEdit* console_input_;
    };
  }
}