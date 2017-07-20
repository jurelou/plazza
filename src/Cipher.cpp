//
// caesar.cpp for Plazza in /home/spring_r/Projet/2016/cpp_plazza
// 
// Made by Romain Springer-Roy
// Login   <romain.springerroy@epitech.eu>
// 
// Started on  Mon Apr 24 14:14:23 2017 Romain Springer-Roy
// Last update Fri Apr 28 14:18:13 2017 augustin marmus
//

#include	<iostream>
#include	<fstream>
#include	<string>
#include	"Cipher.hpp"

namespace Cipher
{
  std::string	*decryptCaesar(std::string& source, int key)
  {
    size_t	i = 0;
    std::string *res;

    res = new std::string(source);
    while (i < res->length())
      {
	if (std::isalpha((*res)[i]))
	  {
	    char offset = isupper((*res)[i]) ? 'A' : 'a';
	    (*res)[i] = (((((*res)[i] + (26 - key)) - offset) % 26) + offset);
	  }
	i++;
      }
    return (res);
  }

  std::string	*decryptXor(const std::string& source, uint16_t *key)
  {
    std::string	*res;
    char	*key_tab;

    res = new std::string(source);
    key_tab = (char *)key;
    for (size_t i = 0; i < res->size(); i++)
      (*res)[i] = (*res)[i] ^ key_tab[i % 2];
    return (res);
  }
}
