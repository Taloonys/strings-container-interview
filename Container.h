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

//------------------------------ 

class Container final
{
public:
    explicit Container();

public:
    /**
     * @brief findString - поиск строки
    */
    bool findString(const std::string& str) const;

    /**
     * @brief insert - вставка одной строки (copy)
    */
    void insert(std::string str_view);

    /** 
     * @brief insert - вставка нескольких строк (copy)
    */
    void insert(std::vector<std::string> str_view_vector);

    /**
     * @brief showContents - выводит в stdout все свои строки
    */
    void showContents();



private:
    std::unordered_set<std::string> m_stringSet; // исходя из того, что строки уникальные
};
