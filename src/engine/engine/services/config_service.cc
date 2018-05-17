#include "config_service.h"

#include <core/logger.h>

#include <tclap/CmdLine.h>

namespace blowbox
{
  namespace engine
  {
    //------------------------------------------------------------------------------------------------------
    ConfigService::ConfigService() :
      IService("ConfigService")
    {

    }
    
    //------------------------------------------------------------------------------------------------------
    ConfigService::~ConfigService()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void ConfigService::Initialize()
    {
      
    }

    //------------------------------------------------------------------------------------------------------
    void ConfigService::Shutdown()
    {

    }
    
    //------------------------------------------------------------------------------------------------------
    void ConfigService::ParseCLI(int argc, char** argv)
    {
      arguments_.argc = argc;
      arguments_.argv = argv;
      ParseCLI(arguments_);
    }

    //------------------------------------------------------------------------------------------------------
    void ConfigService::ParseCLI(const CommandLineArguments& arguments)
    {
      arguments_ = arguments;

      bool failed_parsing_arguments = false;

      try
      {
        TCLAP::CmdLine cmd("Blowbox", ' ', "none", false);
        cmd.setExceptionHandling(false);

        TCLAP::ValueArg<unsigned int> verbosity_arg("v", "verbosity", "The verbosity threshold level by which logged messages should be filtered.", false, 25, "");
        TCLAP::ValueArg<std::string> project_directory_arg("p", "project", "Directory of the project to run.", false, "", "");
        TCLAP::ValueArg<int> width_arg("w", "width", "Width of the window in pixels", false, 1280, "");
        TCLAP::ValueArg<int> height_arg("h", "height", "Height of the window in pixels", false, 1280, "");
        TCLAP::SwitchArg fullscreen_arg("f", "fullscreen", "Launches the application in fullscreen mode", false);

        cmd.add(verbosity_arg);
        cmd.add(project_directory_arg);
        cmd.add(width_arg);
        cmd.add(height_arg);
        cmd.add(fullscreen_arg);

        cmd.parse(arguments_.argc, arguments_.argv);

        cmd_config_.logger_verbosity_level = verbosity_arg.getValue();
        cmd_config_.fullscreen = fullscreen_arg.getValue();
        cmd_config_.height = height_arg.getValue();
        cmd_config_.width = width_arg.getValue();
        cmd_config_.project_directory = Path(project_directory_arg.getValue());
      }
      catch (TCLAP::ArgException& e)
      {
        core::Logger::Error(10, core::MessageSource::Engine, "An error occurred during CLI parsing: %s (argument: %s).", e.error().c_str(), e.argId().c_str());
        failed_parsing_arguments = true;
      }

      if (failed_parsing_arguments)
      {
        core::Logger::Warn(20, core::MessageSource::Engine, "Default command line argument config will be constructed because the command line arguments failed to be parsed.");

        GenerateDefaultCommandLineConfig();
      }
      else
      {
        core::Logger::Log(50, core::MessageSource::Engine, "Command line arguments were parsed successfully.");
      }
    }

    //------------------------------------------------------------------------------------------------------
    const CommandLineConfig& ConfigService::GetCommandLineConfig() const
    {
      return cmd_config_;
    }
    
    //------------------------------------------------------------------------------------------------------
    void ConfigService::GenerateDefaultCommandLineConfig()
    {
      cmd_config_ = {};

      cmd_config_.logger_verbosity_level = 25;
      cmd_config_.fullscreen = false;
      cmd_config_.width = 1280;
      cmd_config_.height = 720;
      cmd_config_.project_directory = Path("");
    }
  }
}