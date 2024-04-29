/**
 * @brief Отвечает за отображение содержания контейнеров
*/
//------------------------------ 

#pragma once 

#include "ICommandUnit.h"

//------------------------------ 

class TerminalShowContentsCmd final : public ICommandUnit
{
public:
    const std::string& text() const override
    {
        return cmdDisplayText;
    };

    void exec(const std::string userInput, ContainerManager& containerManager) const override 
    {
        containerManager.showContents();
    };

private:
    std::string const cmdDisplayText = "Show containers contents";
};