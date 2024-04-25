/**
 * @brief Conditions
 * Есть множество N строк (N > 0), все строки уникальные
 * Есть набор M контейнеров (0 < M < N), каждый контейнер содержит строки (Сколько-то строк из общего набора N)
 * Числа M и N могут задаваться как в коде, так и через stdin.
 * 
 * @brief Task
 * На вход подаётся строка, необходимо найти контейнер с этой строкой и выдать его ID
 * Необходимый функционал:
 *  - Выводить на экран изначальное содержание контейнера
 *  - Выводить необходимую строку (Видимо, по ... по чему???)  
 *  - Выводить ID контейнера
 * 
 * @brief Step 1
 * Распределить строки по контейнерам самому. 
 * - Выводить начальное наполнение контейнеров
 * - Выдавать ID контейнера по запрашиваемой строке
 * 
 * @brief Step 2 
 * Строки по контейнерам разбиты в случайном порядке ??? 
*/

//------------------------------ 

/** 
 * @author Makrousov Vadim
*/

//------------------------------ 

#include <iostream>
// #include <memory>

#include "TerminalHandler.h"
#include "ContainerManager.h" // could be moved to only TerminalHandler

//------------------------------ 

int main() 
{
    // std::unique_ptr<ContainerManager> pContainerManager = std::make_unique<ContainerManager>();
    ContainerManager containerManager;
    TerminalHandler terminal;

    /** 
     * @todo так делать неэтично, но я кое-что попробую потом
    */
    terminal.initContainerManager(&containerManager); 

    return 0;
}
