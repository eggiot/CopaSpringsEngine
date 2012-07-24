/*---------------------------------------
 * ConfigFile.h
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef CONFIGFILE_H
#define CONFIGFILE_H
/*--------------------------------------*/
#include <string>
#include <map>
/*--------------------------------------*/

class ConfigValue
{
private:
    std::string value_;
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
  std::map<std::string,ConfigValue> content_;

public:
  ConfigFile(std::string const& config_filename);
  ConfigValue const& getValue(std::string const& entry) const;
};

/*--------------------------------------*/
#endif /*CONFIGFILE_H*/
