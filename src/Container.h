/**
 * @brief класс контейнера строк, хранит их в неупорядоченном сете
 * 
 * responsibility:
 * - Искать строку внутри контейнера
 * - Добавлять строку 
 * - Добавлять несколько строк с помощью вектора
*/

//------------------------------ 

#pragma once 

#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <random>
#include <algorithm>

#define DEBUG(x) { std::cout << "[DEBUG] - " << __FUNCTION__ << " : " << x << std::endl; }

static auto rng = std::default_random_engine {};

//------------------------------ 

class Container final
{
public:
    /**
     * @brief findString - поиск строки
    */
    bool findString(const std::string& str) const;

    /**
     * @brief insert - вставка одной строки (copy)
    */
    void insert(const std::string str_view);

    /** 
     * @brief insert - вставка нескольких строк (copy)
    */
    void insert(const std::vector<std::string>& str_vector);

    /**
     * @brief showContents - выводит в stdout все свои строки
    */
    void showContents() const;

    /**
     * @brief generateRandomStrings - генерирует определённое кол-во строк со случайным содержанием
    */
    void generateRandomStrings(const uint number_of_strings, const uint string_length);



private:
    std::unordered_set<std::string> m_stringSet; // исходя из того, что строки уникальные + cамый быстрый поиск дефолтный поиск среди других структур
};
