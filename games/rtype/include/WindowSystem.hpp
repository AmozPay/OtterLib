/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** Window manager
*/

#ifndef WINDOW_MANAGER_H_
#define WINDOW_MANAGER_H

#include "OtterCore.hpp"
#include "OtterGraphic.hpp"
#include "RaylibWindow.hpp"

class WindowManager {
public:
  WindowManager(Engine::World &gData,
		const int &width,
		const int &height,
		std::string &title);
  ~WindowManager();
    
  void poolEvent();
  
  void start_draw();
  void end_draw();
  bool isActive();
  EventId convertEnumToId(const int enume);
  
private:
  Engine::World &_gData;
  Raylib::RaylibWindow _window;  
};

#endif