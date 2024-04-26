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
    static std::string str =
        "!@#$%^&*()-=+_)(*&^%$#@!"
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::shuffle(str.begin(), str.end(), rng);

    return str.substr(0, string_length-1);
}

//---------------------------------------------------------------------- 

void Container::generateRandomStrings(const uint number_of_strings, const uint string_length)
{
    DEBUG("number of strings : " + number_of_strings)
    for(int string_count = 0; string_count < number_of_strings; string_count++)
        m_stringSet.insert(generateRandomString(string_length));                    
}