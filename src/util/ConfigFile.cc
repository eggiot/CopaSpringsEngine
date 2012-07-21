/*---------------------------------------
 * ConfigFile.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "ConfigFile.hh"
/*--------------------------------------*/
#include <string>
#include <sstream>
#include <map>
#include <stdlib.h>
#include <fstream>
/*--------------------------------------*/

std::string trim(std::string const& source, char const* delims = " \t\r\n")
{
  std::string result(source);
  std::string::size_type index = result.find_last_not_of(delims);
  if(index != std::string::npos)
    result.erase(++index);

  index = result.find_first_not_of(delims);
  if(index != std::string::npos)
    result.erase(0, index);
  else
    result.erase();
  return result;
}

/*----------------------- CONFIGVALUE ---------------------------*/

ConfigValue::ConfigValue(std::string const& value)
{
    this->value = value;
}

ConfigValue::ConfigValue(double value)
{
    std::stringstream stream;
    stream << value;
    this->value = stream.str();
}

ConfigValue::ConfigValue(ConfigValue const& other)
{
    this->value = other.value;
}


ConfigValue& ConfigValue::operator = (ConfigValue const& other)
{
    this->value = other.value;
    return *this;
}

ConfigValue& ConfigValue::operator = (std::string const& value)
{
    this->value = value;
    return *this;
}

ConfigValue& ConfigValue::operator = (double value)
{
    std::stringstream stream;
    stream << value;
    this->value = stream.str();
    return *this;
}

ConfigValue::operator std::string() const
{
    return value;
}

ConfigValue::operator double() const
{
    return atof(value.c_str());
}


/*----------------------- CONFIGFILE ---------------------------*/

ConfigFile::ConfigFile(std::string const& configFile) {
    std::ifstream file(configFile.c_str());
    if(file.good())
    {
        std::string line;
        std::string name;
        std::string value;
        int equal_position;
        while (std::getline(file,line))
        {
            // skip blank lines
            if (! line.length()) continue;
            // skip comment lines
            if (line[0] == '#') continue;
            // find the position of the equal sign
            equal_position = line.find('=');
            // name is everything before '='
            name  = trim(line.substr(0, equal_position));
            // value is everything after '='
            value = trim(line.substr(equal_position + 1));
            content[name]=ConfigValue(value);
        }
    }
    else
    {
        throw "Config file does not exist";
    }
}

ConfigValue const& ConfigFile::getValue(std::string const& entry) const
{
    std::map<std::string, ConfigValue>::const_iterator result = content.find(entry);

    if (result == content.end()) throw "Does not exist";
    return result->second;
}
