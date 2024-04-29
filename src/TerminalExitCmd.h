
//------------------------------ 

#pragma once 

#include "ICommandUnit.h"

//------------------------------ 

class TerminalExitCmd final : public ICommandUnit
{
public:
    const std::string& text() const override
    {
        return cmdDisplayText;
    };

    void exec(const std::string userInput, ContainerManager& containerManager) const override
    {
        exit(0);
    };

private:
    std::string const cmdDisplayText = "Exit";
};