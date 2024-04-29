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
#include <optional>
#include "Container.h"

//------------------------------ 

typedef unsigned int ContainerId;

//------------------------------ 

class ContainerManager final
{
public:
    /** 
     * @brief setM - устанавливает количество контейнеров M
    */
    void setM(const uint m);

    /** 
     * @brief setN - устанавливает количество строк N
    */
    void setN(const uint n);

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
     * @brief generateContainersRandom - генерирует контейнеры случайным образом (но согласно параметрам M и N)
    */
    void generateContainersRandom();

    /** 
     * @brief showContents - вывод в stdout наполнения контейнеров
    */
    void showContents() const;

    /** 
     * @brief findString - поиск строки по контейнерам 
    */
    std::optional<ContainerId> findString(const std::string& str) const; /// @todo try string_view

    /**
     * @brief setStrLenRand - устанавливает максимальную длину строки для рандомной генерации
    */
    void setStrLenRand(const uint str_len);

    /**
     * @brief getStrLendRand - возвращает установленную максимальную длину строки для рандомной генерации (по умолчанию = 20)
    */
    uint getStrLenRand() const;



private:
    uint m_M = 4;
    uint m_N = 12;

    std::unordered_map<ContainerId, Container> m_containers;

    uint counter = 0;

private:
    void m_createContainers();
    void m_allowRespawn();

private:
    uint m_maxStrLenRand = 20; // допустимо разрешать выбирать максимальную длину строки
};
