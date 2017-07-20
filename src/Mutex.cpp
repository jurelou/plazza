//
// Mutex.cpp for Project-Master in /home/louis/Documents/cpp_plazza
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 07:22:22 2017 jurczy_l
// Last update Mon Apr 24 08:11:46 2017 jurczy_l
//

#include	"Mutex.hpp"

Mutex::Mutex()
{ pthread_mutex_init(&this->_id, NULL); }

Mutex::~Mutex()
{ pthread_mutex_destroy(&this->_id); }

int		Mutex::lock()
{ return pthread_mutex_lock(&this->_id); }

int		Mutex::unlock()
{ return pthread_mutex_unlock(&this->_id); }

int		Mutex::trylock()
{ return pthread_mutex_trylock(&this->_id); }

pthread_mutex_t	Mutex::getId() const
{ return this->_id; }
