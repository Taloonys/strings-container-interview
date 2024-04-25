/**
 * @brief TerminalHandler - должен отвечать за опрос на ввод команд в stdin...  
*/

//------------------------------ 

#pragma once 

#include <string>

#include "ContainerManager.h"

//------------------------------ 

typedef unsigned int uint;

//------------------------------ 

class TerminalHandler final
{
public:
    /**
     * @brief initContainerManager - инициирует работу через терминал с контейнерами
    */
    bool initContainerManager(ContainerManager* containerManager = nullptr);



private:
    std::string         m_input = "";
    ContainerManager*   m_containerManager = nullptr;

private:
    void m_initContainerMessage();
    void m_initContainerSetup();
    uint m_readInputNumber();
    void m_executeCommmands();
};
