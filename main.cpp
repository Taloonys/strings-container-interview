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
#include <memory>
#include "ContainerManager.h"

//------------------------------ 

int main() 
{
    std::unique_ptr<InputControl> pInput = std::make_unique<InputControl>();

    // Сначала спрашиваем надо ли вводить свои M и N
    pInput.get().init();

    // Если надо, то позволяем их ввести

    // Инициируем наполнение контейнеров строками (Представим, что потом можно заменить/добавить функционал с stdin)
    std::unique_ptr<ContainerManager> pContainerManager = std::make_unique<ContainerManager>();

    pContainerManager.get().fillContainers();

    // Пробуем посмотреть на разбиение строк и контейнеров
    pContainerManager.get().showContents();

    // Пробуем посмотреть ID контейнера по запрашиваемой на поиск строке 
    pContainerManager.get().findString("sth");

    // std::printf("Input contatiner number (M) and string number (N)\n"
    //             "current values:\n"
    //             "M = %d \n"
    //             "N = %d \n", M, N);

    // std::cout >> ""
    // std::cin << M; 


    return 0;
}
