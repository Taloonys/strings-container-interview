#include "ContainerManager.h"

//------------------------------ 

void ContainerManager::setM(const uint m)
{
    m_M = m;
}

//---------------------------------------------------------------------- 

void ContainerManager::setN(const uint n)
{
    m_N = n;
}

//---------------------------------------------------------------------- 

uint ContainerManager::getM() const 
{
    return m_M;
}

//---------------------------------------------------------------------- 

uint ContainerManager::getN() const 
{
    return m_N;
}

//---------------------------------------------------------------------- 

void ContainerManager::fillContainers()
{
    /// @todo
}

//---------------------------------------------------------------------- 

void ContainerManager::showContents() const
{
    for(const auto & [contId, container] : m_containers)
    {
        container.showContents();
        /// @todo обработать формат вывода
    }
}

//---------------------------------------------------------------------- 

ContainerId ContainerManager::findString(const std::string& str) const /// @todo возвращать std::optional
{
    /**
     * @bug что-то я не подумал, что мы исключаем дубликаты лишь внутри контейнера, но не глобально,
     * хотя по заданию строки уникальны глобально... допустим, что по заданию это не надо учитывать
    */
    for(const auto & [contId, container] : m_containers)
    {
        if(container.findString(str))
            return contId;
    }

    return 0; /// @details at method's signature
}
