/**
 * @brief Отвечает за заполнение контейнеров случайным образом
*/
//------------------------------ 

#pragma once 

#include "ICommandUnit.h"

//------------------------------ 

class TerminalFillRndCmd final : public ICommandUnit
{
public:
    const std::string& text() const override;
    void exec(const std::string userInput, ContainerManager& containerManager) const override;

private:
    std::string const cmdDisplayText = "Fill containers randomly";

private:
    void m_setMaxLenStr(ContainerManager& containerManager) const;
};