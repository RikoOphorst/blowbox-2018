#include "console_dock.h"

#include <qmainwindow.h>
#include <qdockwidget.h>
#include <qwidget.h>
#include <qgridlayout.h>
#include <qtextbrowser.h>
#include <qcheckbox.h>
#include <qplaintextedit.h>

namespace blowbox
{
  namespace editor
  {
    //------------------------------------------------------------------------------------------------------
    ConsoleDock::ConsoleDock(QMainWindow* main_window) :
      QDockWidget(QStringLiteral("Console"), main_window),
      dock_contents_(nullptr),
      dock_layout_(nullptr),
      console_view_(nullptr),
      show_logs_checkbox_(nullptr),
      show_warnings_checkbox_(nullptr),
      show_errors_checkbox_(nullptr)
    {
      setObjectName(QStringLiteral("console_dock"));
      setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);

      dock_contents_ = new QWidget();
      dock_contents_->setObjectName(QStringLiteral("console_dock_contents"));

      console_view_ = new QTextBrowser(dock_contents_);
      console_view_->setObjectName(QStringLiteral("console_view"));
      console_view_->setGeometry(0, 0, 200, 100);

      show_logs_checkbox_ = new QCheckBox("Logs", dock_contents_);
      show_warnings_checkbox_ = new QCheckBox("Warnings", dock_contents_);
      show_errors_checkbox_ = new QCheckBox("Errors", dock_contents_);

      console_input_ = new QPlainTextEdit(dock_contents_);
      console_input_->setPlaceholderText(QStringLiteral("Insert Lua code..."));

      //console_view_->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum));
      //console_input_->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum, QSizePolicy::ControlType::LineEdit));
      
      dock_layout_ = new QGridLayout(dock_contents_);
      dock_layout_->setObjectName(QStringLiteral("console_dock_layout"));
      dock_layout_->addWidget(show_logs_checkbox_, 0, 0);
      dock_layout_->addWidget(show_warnings_checkbox_, 0, 1);
      dock_layout_->addWidget(show_errors_checkbox_, 0, 2);
      dock_layout_->addWidget(console_view_, 1, 0, 1, 20);
      dock_layout_->addWidget(console_input_, 2, 0, 1, 20);

      dock_layout_->setRowStretch(0, 1);
      dock_layout_->setRowStretch(1, 5);
      dock_layout_->setRowStretch(2, 1);

      setWidget(dock_contents_);

      main_window->addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, this);
    }

    //------------------------------------------------------------------------------------------------------
    ConsoleDock::~ConsoleDock()
    {
      delete console_view_;
      delete dock_layout_;
      delete dock_contents_;
    }
  }
}