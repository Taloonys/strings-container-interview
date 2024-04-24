/**
 * @brief InputControl - должен отвечать за опрос на ввод команд в stdin... но зачем класс... 
 * внутренних состояний нет...
 * тем более, придётся как-то связывать с менеджером контейнеров
*/

//------------------------------ 

#pragma once 

//------------------------------ 

typedef unsigned int uint;

//------------------------------ 

class InputControl final
{
public:
    explicit InputControl();

public:
    bool init();
};
