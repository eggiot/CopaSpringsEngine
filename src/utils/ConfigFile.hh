/*---------------------------------------
 * ConfigFile.hh
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef CONFIGFILE_HH
#define CONFIGFILE_HH
/*--------------------------------------*/
#include <string>
#include <map>
/*--------------------------------------*/

class ConfigValue
{
private:
    std::string value;
public:
    // constructors
    ConfigValue()
    { }
    ConfigValue(std::string const& value);
    ConfigValue(double value);
    ConfigValue(ConfigValue const& other);

    // = operator
    ConfigValue& operator = (ConfigValue const& other);
    ConfigValue& operator = (std::string const& value);
    ConfigValue& operator = (double value);

    // type operators
    operator std::string() const;
    operator double () const;
};

class ConfigFile {
  std::map<std::string,ConfigValue> content;

public:
  ConfigFile(std::string const& config_filename);
  ConfigValue const& getValue(std::string const& entry) const;
};

/*--------------------------------------*/
#endif /*CONFIGFILE_HH*/
