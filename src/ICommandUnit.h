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
    virtual ~ICommandUnit() = default;

public:
    /**
     * @brief Выводит текст, сопоставимый с назначением команды
    */
    virtual     const std::string& text() const = 0;

    /**
     * @brief Производит исполнение команды
    */
    virtual     void exec(const std::string userInput, ContainerManager& containerManager) const = 0;

protected:
      ICommandUnit() = default;
      ICommandUnit(const ICommandUnit & ) = default;
      ICommandUnit & operator = (const ICommandUnit & ) = default;
      ICommandUnit(ICommandUnit && ) noexcept = default;
      ICommandUnit & operator = (ICommandUnit && ) noexcept = default;
};
