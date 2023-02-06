/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibMusic.hpp
*/

#ifndef RAYLIBWINDOW_HPP_
#define RAYLIBWINDOW_HPP_

#include "Raylib.hpp"

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic::Raylib {
    /**
     * @brief The RaylibWindow class for Raylib window management
     */
    class RaylibWindow {
      public:
        /**
         * @brief Construct a new Window object
         * @param height The height of the window
         * @param width The width of the window
         * @param title The title of the window
         */
        RaylibWindow(const int& height, const int& width, const std::string& title);
        /**
         * @brief Destroy the Window object
         */
        ~RaylibWindow();

        /**
         * @brief Set the framerate limit
         * @param framerate: The framerate limit
         * @return Nothing
         */
        static void setFramerateLimit(const int& framerate);
        /**
         * @brief Set the screen height
         * @param height: The height of the screen
         * @return Nothing
         */
        static void setScreenHeight(const int& height);
        /**
         * @brief Set the screen width
         * @param width: The width of the screen
         * @return Nothing
         */
        static void setScreenWidth(const int& width);
        /**
         * @brief Get the screen width
         * @param width: The width of the screen
         * @param height: The height of the screen
         * @return Nothing
         */
        static void setScreenSize(const int& width, const int& height);

        /**
         * @brief Get the width of the window
         * @return The width of the window
         */
        static int getScreenWidth();
        /**
         * @brief Get the height of the window
         * @return The height of the window
         */
        static int getScreenHeight();

        /**
         * @brief Check if the window is open
         * @return true if the window is open, false otherwise
         */
        static bool isOpen();

        /**
         * @brief Start the drawing process
         * @return Nothing
         */
        static void startDrawing();
        /**
         * @brief End the drawing process
         * @return Nothing
         */
        static void endDrawing();
        /**
         * @brief Clear the window
         * @return Nothing
         */
        static void clearBackground();

        /**
         * @brief Close the window
         * @return Nothing
         */
        static void closeWindow();
    };
} // namespace Otter::Graphic::Raylib

#endif /* !RAYLIBWINDOW_HPP_ */