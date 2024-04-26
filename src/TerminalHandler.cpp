#include <iostream>
#include <optional>
#include "TerminalHandler.h"

#define DEBUG(x) { std::cout << "[DEBUG] : " << x << std::endl; }

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

/**
 * @brief принимает строку и возвращает std::optional<uint>
*/
std::optional<uint> readInputNumber(const std::string& input) 
{
        std::optional<uint> number;

        try
        {
            if(std::stoi(input) < 0)
            {
                DEBUG("number is less than 0")
                return number;
            }

            number = static_cast<uint>(std::stoi(input)); // вернёт значение
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << "Is not a valid number" << std::endl;
        }

        // DEBUG("input read: " + number.value())
        return number; // если вернёт nulltopt, то обработать внешне
}

//------------------------------------------------------------------------------- 

bool TerminalHandler::m_trySetupValues()
{
    std::cout << "number of containers M = ";
    std::getline(std::cin, m_input);
    if(not readInputNumber(m_input).has_value()) 
        return false;

    const uint m = readInputNumber(m_input).value();

    std::cout << "total number of strings N = ";
    std::getline(std::cin, m_input);
    if(not readInputNumber(m_input).has_value()) 
        return false;

    const uint n = readInputNumber(m_input).value();

    // Необходимо сохранять именно пару
    m_containerManager->setM(m);
    m_containerManager->setN(n);

    return true;
}

//------------------------------------------------------------------------------- 

void TerminalHandler::m_initContainerSetup()
{
    while(1)
    {
        std::cout << "Would you like to change M and N? (y/Y or n/N)";
        std::getline(std::cin, m_input);

        if(m_input == "Y" or m_input == "y") /// Даа, вложенность ... 
        {
            // Считаю, что если вводим какие-то странные значения, то можно и изменить своё мнение
            if(not m_trySetupValues()) continue;
            
            break;
        }
        
        if(m_input == "N" or m_input == "n")
            break;
        
        std::cout << "Wrong input" << std::endl;
        continue; // нельзя выйти

    }

    m_containerManager->fillContainers();// go to fill containers from compile time data
    std::cout << "-Containers are pre-filled-";

    m_executeCommmands();
}

//------------------------------------------------------------------------------- 

void TerminalHandler::m_findString()
{
    std::cout << "Input the string you want to find:\n";
    std::getline(std::cin, m_input);

    ContainerId id;
    try
    {
        id = m_containerManager->findString(m_input).value();
    }
    catch(const std::bad_optional_access& e)
    {
        std::cout << "None of containers holds this string" << std::endl;
        return;
    }

    std::cout << "This string is in container: " << id << std::endl;
}

//------------------------------------------------------------------------------- 

void TerminalHandler::m_initCmdsMessageMenu()
{

    std::cout << std::endl 
              << "[Available commands]" << std::endl;

    for(const auto& cmd : m_cmdOptions)
        std::cout << cmd.id << " - " << cmd.text << std::endl;
}

//------------------------------------------------------------------------------- 

void TerminalHandler::m_executeCommmands()
{
    // Ожидаем команды
    while(1)
    {
        m_initCmdsMessageMenu();

        std::getline(std::cin, m_input);
        
        uint cmdId; // Прочитать номер команды
        try
        {
            cmdId = readInputNumber(m_input).value();
        }
        catch(const std::exception& e)
        {
            std::cout << std::endl;
            continue;
        }
        
        switch(cmdId) // исполнить команду
        {
        case E_EXIT: return;
        
        case E_FIND_STRING:
            m_findString();
            continue;

        case E_SHOW_CONTENTS:
            m_containerManager->showContents();
            continue;
        
        default: 
            std::cout << "invalid input";
            continue;
        }

    }
}