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
    /**
    * @brief UI controller for the Console dock window in the editor.
    * 
    * Controls all the UI inside of the Console dock window in the editor.
    * Automatically syncs up with the core::Logger to redirect output towards
    * the console view inside of the dock window.
    */
    class ConsoleDock
    {
    public:
      /**
      * @brief Constructs a console dock controller.
      * @param[in] contents The contents widget of the console dock.
      * @param[in] console_view The widget inside of which the logged messages get displayed.
      * @param[in] console_input The widget that allows the user to type custom commands.
      * @param[in] submit_button The widget that allows the user to submit their custom commands.
      */
      ConsoleDock(
        QWidget* contents,
        QTextBrowser* console_view,
        QTextEdit* console_input,
        QPushButton* submit_button
      );

      /**
      * @brief Destructs the console dock controller.
      */
      ~ConsoleDock();

    private:
      /**
      * @brief The function that is used as the listener for message receiving from the core::Logger.
      * @param[in] user_data The userdata that was set on the core::Logger - this is a pointer to the ConsoleDock.
      * @param[in] message The message that should be logged.
      */
      static void MessageReceiver(void* user_data, const core::Message& message);

      /**
      * @brief Processes a Message and adds it appropriately to the console view.
      * @param[in] message The message that should be logged.
      */
      void ProcessMessage(const core::Message& message);

      /**
      * @brief Converts a time point to a string ready to be displayed.
      * @param[in] time The time point to be converted.
      * @param[out] out_parsed_time Output variable where the parsed string should be put.
      */
      void ParseTimeStamp(const std::chrono::time_point<std::chrono::system_clock>& time, String* out_parsed_time);

      /**
      * @brief Gets the correct QTextCharFormat for a message type.
      * @param[in] type The type of message you want to get the text format for.
      * @returns A QTextCharFormat that should be used to display the message of the specified type.
      */
      QTextCharFormat GetCharFormatByMessageType(const core::MessageType& type);

    private:
      QWidget* dock_contents_;      //!< The contents widget of the dock view.
      QTextBrowser* console_view_;  //!< The text browser widget in which we display all logged messages.
      QTextEdit* console_input_;    //!< The input widget that allows the user to write commands.
      QPushButton* submit_button_;  //!< The button widget that allows the user to submit commands written inside of the console_input_.
    };
  }
}