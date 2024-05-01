#include <iostream>

#include "TerminalHandler.h"

//------------------------------ 

TerminalHandler::TerminalHandler()
{
    srand(time(0));
}

//---------------------------------------------------------------------- 

void TerminalHandler::initContainerManager()
{
    m_initCmdList();    
    m_execution();
}

//---------------------------------------------------------------------- 

void TerminalHandler::m_initCmdList()
{
    m_cmdVec.push_back(std::make_unique<TerminalExitCmd>());
    m_cmdVec.push_back(std::make_unique<TerminalSetValsCmd>());
    m_cmdVec.push_back(std::make_unique<TerminalPrefillCmd>());
    m_cmdVec.push_back(std::make_unique<TerminalFillRndCmd>());
    m_cmdVec.push_back(std::make_unique<TerminalShowContentsCmd>());
    m_cmdVec.push_back(std::make_unique<TerminalFindStrCmd>());
}

//---------------------------------------------------------------------- 

void TerminalHandler::m_showSetupVals()
{
    std::cout << "[Current Params]" << std::endl;
    std::cout << "\t M = " << containerManager.getM() << std::endl;
    std::cout << "\t N = " << containerManager.getN() << std::endl;
}

//---------------------------------------------------------------------- 

void TerminalHandler::m_showCmdList()
{
    for(int i = 0; i < m_cmdVec.size(); i++)
        std::cout << i << " - " << m_cmdVec[i].get()->text() << std::endl;
}

//---------------------------------------------------------------------- 

void TerminalHandler::m_execution()
{
    std::string input;

    while(1)
    {
        std::cout << std::endl;

        // Show cmd message and m/n info everytime
        m_showSetupVals();
        m_showCmdList(); /** @todo not optimized call*/

        // Work with input
        std::getline(std::cin, input);
        
        // if weird input
        if(!TerminalRequisites::convertStrToUint(input).has_value())
        {
            std::cout << "Invalid option" << std::endl;
            continue;
        }

        // if invalid chosen menu
        if(TerminalRequisites::convertStrToUint(input).value() > m_cmdVec.size() - 1)
        {
            std::cout << "Invalid option" << std::endl;
            continue;
        }

        m_cmdVec[TerminalRequisites::convertStrToUint(input).value()].get()->exec(input, containerManager);
    }
}