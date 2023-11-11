/*
** EPITECH PROJECT, 2023
** Game-Jam
** File description:
** SceneManager
*/

#pragma once

#include <map>
#include <string>
#include <iostream>
#include "IScene.hpp"

class SceneManager {
public:
    SceneManager();

    void addMenu(std::string menuName, IScene *scene);
    void display(void *data);
    void changeMenu(std::string sceneName);

protected:
    std::string currScene_ = "None";
    std::string prevScene_ = "None";
    std::map<std::string, IScene*> _sceneList;
};
