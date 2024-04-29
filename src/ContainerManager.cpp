#include "ContainerManager.h"

//------------------------------ 

void ContainerManager::setM(const uint m)
{
    if(m == 0)
    {
        std::cout << "(Rules are: 0 < M < N) M could not be 0, returned M = " << m_M << std::endl;
        return;
    }

    m_M = m;
}

//---------------------------------------------------------------------- 

void ContainerManager::setN(const uint n)
{
    if(n == 0)
    {
        std::cout << "(Rules are: 0 < M < N) N could not be 0, returned N = " << m_N << std::endl;
        return;
    }

    /** @todo top 10 cringiest limitations treatments */
    if(n < m_M)
    {
        std::cout << "(Rules are: 0 < M < N) N could not be less than M, setted up N = " << m_M + 1 << std::endl;
        m_N = m_M + 1;
        return;
    }

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

void ContainerManager::m_allowRespawn()
{
    if(not m_containers.empty())
        m_containers.clear(); // for 2 step i allow to respawn containers
}

//---------------------------------------------------------------------- 

void ContainerManager::fillContainers() // step 1
{
    m_allowRespawn();

    for (int i = 0; i < m_N; ++i) {
        int containerKey = i % m_M;
        m_containers[containerKey].insert("string " + std::to_string(i + 1));
    }
}

//---------------------------------------------------------------------- 

void ContainerManager::showContents() const
{
    /**
     * @todo добавить перегрузку с методом на то, как отображать строки в табличном виде
    */
    if(m_containers.empty())
    {
        std::cout << " ----- There are no containers generated -----" << std::endl;
        return;
    }

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
    m_allowRespawn();

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

/**
 * @brief генерирует вектор случайных чисел заданной длины и сумма всех таких чисел равна заданной summ
*/
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

    return vec;
}

//---------------------------------------------------------------------- 

void ContainerManager::generateContainersRandom()
{
    m_createContainers();
    
    std::vector<uint> randNums(std::move(randNumVec(m_M, m_N)));
    uint num;

    for(auto& [contId, container] : m_containers)     
    {
        num = randNums.front();
        randNums.erase(randNums.begin());
        container.generateRandomStrings(num, m_maxStrLenRand);
    }
}