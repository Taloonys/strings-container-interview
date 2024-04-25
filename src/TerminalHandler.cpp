#include <iostream>
#include "TerminalHandler.h"

//------------------------------ 

bool TerminalHandler::initContainerManager(ContainerManager* containerManager)
{
    m_containerManager = containerManager;   

    if(m_containerManager == nullptr) // пока не уверен, кому можно владеть или кто будет создавать
        return false; 

    m_initContainerMessage();

    return true;
}

//------------------------------------------------------------------------------- 

void TerminalHandler::m_initContainerMessage()
{
    std::printf("m_input contatiner number (M) and string number (N)\n"
                "current values:\n"
                "\tM = %d \n"
                "\tN = %d \n",
                m_containerManager->getM(),
                m_containerManager->getN());

   m_initContainerSetup(); 
}

//------------------------------------------------------------------------------- 

void TerminalHandler::m_initContainerSetup()
{
    std::cout << "Would you like to change them? (y/Y or n/N)";
    std::cin >> m_input;

    if(m_input == "Y" or m_input == "y")
    {
        std::cout << "m_input M = ";
        m_containerManager->setM(m_readInputNumber());

        std::cout << "m_input N = ";
        m_containerManager->setN(m_readInputNumber());
    }
    else if(m_input == "N" or m_input == "n")
    {
        m_containerManager->fillContainers();// go to fill containers from compile time data
        std::cout << "Containers are pre-filled";
    }
    else 
    {
        std::cout << "Wrong input";
    }

    m_executeCommmands();
}

//------------------------------------------------------------------------------- 

uint TerminalHandler::m_readInputNumber()
{
        // std::optional<uint> number;
        /// @todo use optional after adding c++17 standard

        uint number = 666;
        while(1)
        {
            std::cin >> m_input;

            try
            {
                number = static_cast<uint>(std::stoi(m_input)); // static_cast here is useless
                break;
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << "Is not a valid number";
            }
            catch(const std::out_of_range& e)
            {
                std::cout << "Should m_input only positive numbers or 0";
            }

            // if(number != 666)
            //     break;
        }

        return number;
}

//------------------------------------------------------------------------------- 

void TerminalHandler::m_executeCommmands()
{
    /// @todo commands should be under somekind of defines
    std::cout << "You may input commands.." << std::endl 
                << "[Available commands]" << std::endl 
                << "find string" << std::endl 
                << "show contents" << std::endl << std::endl;

    /// @todo commands and their executes should be under somekind of list-of-commmands

    // Ожидаем команды
    while(1)
    {
        std::getline(std::cin, m_input);

        if(m_input == "find string")
        {
            std::cout << "Input the string you want to find:\n";
            std::getline(std::cin, m_input);

            std::cout << "This string is in container: " << m_containerManager->findString(m_input) << std::endl;
        }

        if(m_input == "show contents")
            m_containerManager->showContents();

        // Выйти из приложения 
        if(m_input == "exit")
            break; // leave the cycle

    }
}