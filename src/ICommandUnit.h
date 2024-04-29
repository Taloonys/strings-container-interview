#pragma once

//------------------------------ 

#include <string>
#include <iostream>
#include "PreDefines.h"
#include "ContainerManager.h"

//------------------------------ 

class ICommandUnit
{
public:
    /**
     * @brief Выводит текст, сопоставимый с назначением команды
    */
    virtual     const std::string& text() const = 0;

    /**
     * @brief Производит исполнение команды
    */
    virtual     void exec(const std::string userInput, ContainerManager& containerManager) const = 0;
};