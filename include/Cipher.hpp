//
// Cipher.hpp for Plazza in /home/spring_r/Projet/2016/cpp_plazza/include
// 
// Made by Romain Springer-Roy
// Login   <romain.springerroy@epitech.eu>
// 
// Started on  Tue Apr 25 11:10:49 2017 Romain Springer-Roy
// Last update Fri Apr 28 14:16:27 2017 augustin marmus
//

#ifndef		CIPHER_HPP_
# define	CIPHER_HPP_

# include	<string>

namespace	Cipher
{
  std::string*		decryptCaesar(std::string& source, int key);
  std::string	*decryptXor(const std::string& source, uint16_t *key);
}

#endif
