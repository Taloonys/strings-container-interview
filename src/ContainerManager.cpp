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

void ContainerManager::fillContainers() // этап 1
{
    m_createContainers();
    
    uint strsPerContainer = (m_N / m_M);
    for(auto& [id, container] : m_containers)
    {
        for(int i = 0; i < strsPerContainer; i++) // надеюсь, что в текущем случае не волнует О(n^2)
        {
            container.insert(("string" + std::to_string(i)) + "__" + std::to_string(counter++));    
        }
    }

}

//---------------------------------------------------------------------- 

void ContainerManager::showContents() const
{
    for(const auto & [contId, container] : m_containers)
    {
        std::printf("----- Container № %d -----\n", contId);
        container.showContents();
        std::cout <<"--------------------------\n";
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

//---------------------------------------------------------------------- 

void ContainerManager::m_createContainers()
{
    for(ContainerId id = 0; id < m_M; id++)
    {
        Container container;
        m_containers.insert({id, container});
    }
}