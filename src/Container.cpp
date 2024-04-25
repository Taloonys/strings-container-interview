#include "Container.h"

//------------------------------ 

/** 
 * @details could use string_view but it causes ultra minor changes here
*/
bool Container::findString(const std::string& str) const 
{
    if(m_stringSet.find(str) != m_stringSet.end())
        return true;

    return false;
}

//---------------------------------------------------------------------- 

void Container::insert(const std::string str_view)
{
    if(str_view.empty())
        return;

    m_stringSet.insert(std::string(str_view));
}

//---------------------------------------------------------------------- 

void Container::insert(const std::vector<std::string>& str_vector)
{
    if(str_vector.empty())
        return;

    for(const std::string& str : str_vector)
    {
        m_stringSet.insert(str);
    }
}

//---------------------------------------------------------------------- 

void Container::showContents() const
{
    if(m_stringSet.empty())
    {
        std::cout << "Container is empty" << std::endl;
        return;
    }

    for(const std::string& str : m_stringSet)
    {
        std::cout << str << std::endl;
    }
}