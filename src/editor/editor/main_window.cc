#include "main_window.h"

#include "editor/hierarchy_dock.h"
#include "editor/assets_dock.h"
#include "editor/console_dock.h"
#include "editor/inspector_dock.h"

#include <qapplication.h>
#include <qgridlayout.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qwidget.h>
#include <qstylefactory.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qevent.h>
#include <qsettings.h>

#include <iostream>

namespace blowbox
{
  namespace editor
  {
    //--------------------------------------------------------------------------
    MainWindow::MainWindow(QApplication* app) :
      app_(app)
    {
      Q_INIT_RESOURCE(style);

      QFile f(":qdarkstyle/style.qss");
      
      if (!f.exists())
      {
        printf("Unable to set stylesheet, file not found\n");
      }
      else
      {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        app_->setStyleSheet(ts.readAll());
      }

      app_->setStyle(QStyleFactory::create("Fusion"));
      app_->setWindowIcon(QIcon(":/qss_icons/rc/blowbox_editor_ico.png"));

      setObjectName(QStringLiteral("main_window"));
      setWindowModality(Qt::WindowModality::WindowModal);
      setWindowIcon(QIcon(":/qss_icons/rc/blowbox_editor_ico.png"));
      setEnabled(true);
      resize(1280, 720);
      setMinimumSize(QSize(400, 400));
      setAutoFillBackground(false);
      setTabShape(QTabWidget::Rounded);
      setDockOptions(QMainWindow::AllowNestedDocks | QMainWindow::AnimatedDocks | QMainWindow::VerticalTabs);

      central_widget_ = new QWidget(this);
      central_widget_->setObjectName(QStringLiteral("main_window_central_widget"));

      grid_layout_widget_ = new QWidget(central_widget_);
      grid_layout_widget_->setObjectName(QStringLiteral("grid_layout_widget"));
      grid_layout_widget_->setGeometry(QRect(0, 0, 840, 550));

      central_layout_ = new QGridLayout(grid_layout_widget_);
      central_layout_->setObjectName("central_layout");
      central_layout_->setContentsMargins(QMargins(0, 0, 0, 0));

      render_view_ = new QWidget(grid_layout_widget_);
      render_view_->setObjectName(QStringLiteral("render_view"));
      render_view_->setMinimumSize(QSize(640, 360));
      render_view_->setAcceptDrops(false);

      central_layout_->addWidget(render_view_, 0, 0, 1, 1);

      setCentralWidget(central_widget_);

      menubar_ = new QMenuBar(this);
      menubar_->setObjectName(QStringLiteral("menubar"));
      menubar_->setGeometry(QRect(0, 0, 1280, 21));

      menu_file_ = new QMenu("File", menubar_);
      menu_file_->setObjectName(QStringLiteral("menu_file"));

      menu_edit_ = new QMenu("Edit", menubar_);
      menu_edit_->setObjectName(QStringLiteral("menu_edit"));

      menu_assets_ = new QMenu("Assets", menubar_);
      menu_assets_->setObjectName(QStringLiteral("menu_assets"));

      menubar_->addAction(menu_file_->menuAction());
      menubar_->addAction(menu_edit_->menuAction());
      menubar_->addAction(menu_assets_->menuAction());

      setMenuBar(menubar_);

      hierarchy_dock_ = new HierarchyDock(this);
      assets_dock_ = new AssetsDock(this);
      console_dock_ = new ConsoleDock(this);
      inspector_dock_ = new InspectorDock(this);

      QMetaObject::connectSlotsByName(this);

      QSettings settings("Riko Ophorst", "Blowbox");
      QByteArray saved_geometry = settings.value("geometry").toByteArray();
      restoreGeometry(saved_geometry);
      QByteArray saved_state = settings.value("windowState").toByteArray();
      restoreState(saved_state);
    }

    //------------------------------------------------------------------------------------------------------
    MainWindow::~MainWindow()
    {
      
    }

    //------------------------------------------------------------------------------------------------------
    void MainWindow::closeEvent(QCloseEvent *event)
    {
      QSettings settings("Riko Ophorst", "Blowbox");
      settings.setValue("geometry", saveGeometry());
      settings.setValue("windowState", saveState());
    }
  }
}