#include "TerminalFillRndCmd.h"

//------------------------------ 

const std::string& TerminalFillRndCmd::text() const
{
    return cmdDisplayText;
};

//---------------------------------------------------------------------- 

void TerminalFillRndCmd::exec(const std::string userInput, ContainerManager& containerManager) const
{
    m_setMaxLenStr(containerManager);
    containerManager.generateContainersRandom();
};

//---------------------------------------------------------------------- 

void TerminalFillRndCmd::m_setMaxLenStr(ContainerManager& containerManager) const 
{
    std::string input;

    while(1)
    {
        std::cout << "Current max length for random string is: " << containerManager.getStrLenRand() << std::endl
                  << "input correct value (>0) if you want to change it: " << std::endl;
        std::getline(std::cin, input);

        if(!TerminalRequisites::convertStrToUint(input).has_value())
            break;

        if(TerminalRequisites::convertStrToUint(input).value() == 0)
        {
            std::cout << "Invalid value, it should be > 0" << std::endl;
            break;
        }

        containerManager.setStrLenRand(TerminalRequisites::convertStrToUint(input).value());
        return;
    }
}

