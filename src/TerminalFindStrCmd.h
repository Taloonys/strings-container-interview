/**
 * @brief Отвечает за инициацию команды поиска строки
*/
//------------------------------ 

#pragma once 

#include "ICommandUnit.h"

//------------------------------ 

class TerminalFindStrCmd final : public ICommandUnit
{
public:
    const std::string& text() const override
    {
        return cmdDisplayText;
    };

    void exec(const std::string userInput, ContainerManager& containerManager) const override 
    {
        std::string input;
        std::cout << "Input the string you want to find:\n";
        std::getline(std::cin, input);

        if(!containerManager.findString(input).has_value())
        {
            std::cout << "None of containers holds this string" << std::endl;
            return;
        }
        
        std::cout << "--- This string is in container: " << containerManager.findString(input).value() << std::endl;
    };

private:
    std::string const cmdDisplayText = "Find string";
};