/**
 * @brief Отвечает за установку количества значений контейнеров (М) и количества строк (N)
*/
//------------------------------ 

#pragma once 

#include "ICommandUnit.h"

//------------------------------ 

class TerminalSetValsCmd final : public ICommandUnit
{
public:
    const std::string& text() const override;
    void exec(const std::string userInput, ContainerManager& containerManager) const override;

private:
    std::string const cmdDisplayText = "Set number of containers (M) and number of string (N)";

private:
    void m_setM(ContainerManager& containerManager) const;
    void m_setN(ContainerManager& containerManager) const;
};