#include "TerminalSetValsCmd.h"

//------------------------------ 

const std::string& TerminalSetValsCmd::text() const
{
    return cmdDisplayText;
};

//---------------------------------------------------------------------- 

void TerminalSetValsCmd::exec(const std::string userInput, ContainerManager& containerManager) const
{
    // Init values setting
    m_setM(containerManager);
    m_setN(containerManager);
};

//---------------------------------------------------------------------- 

void TerminalSetValsCmd::m_setM(ContainerManager& containerManager) const
{
    std::string input;

    while(1)
    {
        std::cout << "Input M: ";
        std::getline(std::cin, input);

        if(!TerminalRequisites::convertStrToUint(input).has_value())
            continue;
        
        containerManager.setM(TerminalRequisites::convertStrToUint(input).value());
        return;
    }
};

//---------------------------------------------------------------------- 

void TerminalSetValsCmd::m_setN(ContainerManager& containerManager) const
{
    std::string input;

    while(1)
    {
        std::cout << "Input N: ";
        std::getline(std::cin, input);

        if(!TerminalRequisites::convertStrToUint(input).has_value())
            continue;
        
        containerManager.setN(TerminalRequisites::convertStrToUint(input).value());
        return;
    }
};