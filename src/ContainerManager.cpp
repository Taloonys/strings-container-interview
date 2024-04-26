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
    /**
     * @todo добавить перегрузку с методом на то, как отображать строки в табличном виде
    */
    for(const auto & [contId, container] : m_containers)
    {
        std::printf("----- Container № %d -----\n", contId);
        container.showContents();
        std::cout <<"--------------------------\n";
    }
}

//---------------------------------------------------------------------- 

std::optional<ContainerId> ContainerManager::findString(const std::string& str) const /// @todo возвращать std::optional
{
    /**
     * @bug что-то я не подумал, что мы исключаем дубликаты лишь внутри контейнера, но не глобально,
     * хотя по заданию строки уникальны глобально... допустим, что по заданию это не надо учитывать
    */
    std::optional<ContainerId> id;

    for(const auto & [contId, container] : m_containers)
    {
        if(container.findString(str))
        {
            id = contId;
            break;
        }
    }

    return id; /// @details at method's signature
}

//---------------------------------------------------------------------- 

void ContainerManager::m_createContainers()
{
    if(not m_containers.empty())
        m_containers.clear(); // for 2 step i allow to respawn containers

    DEBUG("")
    for(ContainerId id = 0; id < m_M; id++)
    {
        Container container;
        m_containers.insert({id, container});
    }
}

//---------------------------------------------------------------------- 

void ContainerManager::setStrLenRand(const uint str_len)
{
    m_maxStrLenRand = str_len;
}

//---------------------------------------------------------------------- 

uint ContainerManager::getStrLenRand() const
{
    return m_maxStrLenRand;
}

//---------------------------------------------------------------------- 

const std::vector<uint> randNumVec(const uint number_of_elements, const uint summ) 
{
    std::vector<uint> vec; 

    uint summ_down = summ;

    for(int i = 0; i < number_of_elements - 1; i++)
    {
        uint num = rand() % (summ - number_of_elements + 1) + 1;
        vec.push_back(num);
        summ_down -= num;
    }

    vec.push_back(summ - summ_down);

    for(const auto val : vec)
        std::cout << val << " " << std::endl;
    
    return vec;
}

//---------------------------------------------------------------------- 

void ContainerManager::generateContainersRandom()
{
    m_createContainers();
    
    // srand(m_N);

    std::vector<uint> randNums(std::move(randNumVec(m_M, m_N)));
    uint num;

    for(auto& [contId, container] : m_containers)     
    {
        num = randNums.front();
        DEBUG("vec front is " + std::to_string(randNums.front()))
        randNums.erase(randNums.begin());
        DEBUG("num is " + std::to_string(num))
        container.generateRandomStrings(num, m_maxStrLenRand);
    }
}