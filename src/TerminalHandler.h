/**
 * @brief TerminalHandler - должен отвечать за опрос на ввод команд в stdin... 
 * Реализована абстрактная фабрика команд
*/

//------------------------------ 

#pragma once 

#include <string>
#include <memory>

#include "ContainerManager.h"
/** @ingroup Командные юниты, где каждый отвечает за своё исполнение команды */
#include "TerminalExitCmd.h"
#include "TerminalSetValsCmd.h"
#include "TerminalPrefillCmd.h"
#include "TerminalFillRndCmd.h"
#include "TerminalShowContentsCmd.h"
#include "TerminalFindStrCmd.h"

//------------------------------ 

class TerminalHandler final
{
public:
    explicit TerminalHandler();

public:
    /**
     * @brief initContainerManager - инициирует работу через терминал с контейнерами
    */
    void initContainerManager();



private:
    ContainerManager   containerManager;

private:
    void m_initCmdList();
    void m_showSetupVals();
    void m_showCmdList();
    void m_execution();

private:
    std::vector<std::unique_ptr<ICommandUnit>> m_cmdVec;
};