/** 
 * @brief класс для менеджмента контейнерами строк @ref Container
 * 
 * responsibility:
 * - Хранить общее кол-во контейнеров и строк (M и N)
 * - Осуществлять заполнение контейнеров на этапе компиляции
 * - Некоторого рода микро-фасад для поиска строки по контейнерам и отображение ID нужного
 * - Отображать наполнение контейнеров
 * - Менеджмент работы контейнеров
*/

//------------------------------ 

#pragma once

#include <unordered_map>

#include "Container.h"

//------------------------------ 

typedef unsigned int uint;
typedef unsigned int ContainerId;

//------------------------------ 

class ContainerManager final
{
public:
    explicit ContainerManager(uint M, uint N);

public:
    /**
     * @brief getM - узнать кол-во контейнеров
    */
    uint getM() const;

    /** 
     * @brief getN - узнать кол-во строк всего в контейнерах
    */
    uint getN() const;

    /**
     * @brief fillContainers - заполнить контейнерами строками (на этапе компиляции)
    */
    void fillContainers();

    /** 
     * @brief showContents - вывод в stdout наполнения контейнеров
    */
    void showContents() const;

    /** 
     * @brief findString - поиск строки по контейнерам 
    */
    bool findString(const std::string& str) const;



private:
    uint m_M;
    uint m_N;

    std::unordered_map<ContainerId, Container> m_containers;

};
