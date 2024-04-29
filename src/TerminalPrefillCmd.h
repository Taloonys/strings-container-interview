/**
 * @brief Отвечает за заполнение контейнеров на основе того, что выражено в коде
*/
//------------------------------ 

#pragma once 

#include "ICommandUnit.h"

//------------------------------ 

class TerminalPrefillCmd final : public ICommandUnit
{
public:
    const std::string& text() const override
    {
        return cmdDisplayText;
    };

    void exec(const std::string userInput, ContainerManager& containerManager) const override
    {
        containerManager.fillContainers();
        std::cout << " -- Containers were pre-filled -- " << std::endl;
    };

private:
    std::string const cmdDisplayText = "Prefill containers with contents, provided in-code";
};