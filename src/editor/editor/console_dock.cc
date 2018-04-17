#include "console_dock.h"

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
      
    }

    //------------------------------------------------------------------------------------------------------
    ConsoleDock::~ConsoleDock()
    {
      
    }
  }
}