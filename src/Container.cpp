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

//---------------------------------------------------------------------- 

std::string generateRandomString(const uint string_length)
{
    // copying char set for string
    std::string str(RandRequisites::chars_preset);

    // mixing it randomly with default random engine
    std::shuffle(str.begin(), str.end(), RandRequisites::rng);

    const uint randomLen = (rand() % string_length) + 1; // [1..string_length]

    // returning the random length of that mixable string
    return str.substr(0, (randomLen - 1) == 0 ? 1 : randomLen - 1); // ternar for preventing zero size strs
}

//---------------------------------------------------------------------- 

void Container::generateRandomStrings(const uint number_of_strings, const uint string_length)
{
    if(number_of_strings == 0)
        return;

    for(int string_count = 0; string_count < number_of_strings; string_count++)
        m_stringSet.insert(generateRandomString(string_length));                    

    // DEBUG("container size is " + getSize())
}

//---------------------------------------------------------------------- 

uint Container::getSize() const
{
    return m_stringSet.size();
}