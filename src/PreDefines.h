#pragma once 

/**
 * @brief Group of global Defines, TypeDefs, Enums, Funcs and etc
*/

//------------------------------ 

#include <optional>
#include <stdexcept>
#include <iostream>
#include <random>
#include <algorithm>

//------------------------------ 

/**
 * @defgroup
 */

typedef unsigned int uint;

#define DEBUG(x) { std::cout << "[DEBUG] - " << __FUNCTION__ << " : " << x << std::endl; }

//------------------------------ 

namespace RandRequisites
{
    static auto rng = std::default_random_engine {};

    static std::string chars_preset =
        // "!@#$%^&*()-=+_)(*&^%$#@!"
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};

//------------------------------ 

namespace TerminalRequisites
{
    /**
     * @brief Функция, обрабатывающая неверное преобразование строки в uint
    */
    static std::optional<uint> convertStrToUint(const std::string& input) 
    {
        std::optional<uint> number;

        try
        {
            number = static_cast<uint>(std::stoul(input)); // try cast to uint
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << "Is not a valid number" << std::endl;
        }

        return number; // если вернёт nulltopt, то обработать внешне
    }
};

//------------------------------ 