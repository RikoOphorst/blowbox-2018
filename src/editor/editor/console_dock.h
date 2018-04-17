#pragma once

#include <qdockwidget.h>

class QWidget;
class QBoxLayout;
class QTextBrowser;
class QCheckBox;
class QTextEdit;
class QSplitter;
class QComboBox;
class QPushButton;

namespace blowbox
{
  namespace editor
  {
    class ConsoleDock
    {
    public:
      ConsoleDock(
        QWidget* contents, 
        QComboBox* channels_filter, 
        QCheckBox* logs_checkbox, 
        QCheckBox* warnings_checkbox, 
        QCheckBox* errors_checkbox,
        QTextBrowser* console_view,
        QTextEdit* console_input,
        QPushButton* submit_button
      );
      ~ConsoleDock();

    private:
      QWidget* dock_contents_;
      QTextBrowser* console_view_;

      QComboBox* channels_filter_;
      QCheckBox* logs_checkbox_;
      QCheckBox* warnings_checkbox_;
      QCheckBox* errors_checkbox_;

      QTextEdit* console_input_;
      QPushButton* submit_button_;
    };
  }
}