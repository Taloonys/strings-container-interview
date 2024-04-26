/**
 * @brief TerminalHandler - должен отвечать за опрос на ввод команд в stdin...  
 * @details изначально не должен был быть класом, но была идея сделать фабрику опций работы с контейнерами
 * и командами
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
     * @details потом что класс ответственен за терминал, а работа ведётся только с 1 субъектом, поэтому не конструктор
    */
    bool initContainerManager(ContainerManager* containerManager = nullptr);



private:
    std::string         m_input = ""; // только косплеит статик переменную, правильнее будет каждый раз делать новую
    ContainerManager*   m_containerManager = nullptr;

private:
    void m_initContainerMessage();

    void m_initContainerSetup();
    bool m_trySetupValues();

    void m_initCmdsMessageMenu();
    void m_executeCommmands();
    void m_findString();
    void m_randContainersContent();

private: 
    enum ContainerCmds
    {
        E_EXIT          = 0,
        E_FIND_STRING   = 1,
        E_SHOW_CONTENTS = 2,
        E_RAND_STRING   = 3,
    };

    struct CmdOption {
        const uint id;
        const std::string text;
    };

    const std::vector<CmdOption> m_cmdOptions {
        {E_EXIT, "exit"}, 
        {E_FIND_STRING, "find string"}, 
        {E_SHOW_CONTENTS, "show contetnts"},
        {E_RAND_STRING, "generate and fill containers randomly"}
    };
};
