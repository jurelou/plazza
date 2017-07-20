//
// Process.cpp for Project-Master in /home/louis/Documents/cpp_plazza/src
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 08:19:20 2017 jurczy_l
// Last update Fri Apr 28 15:06:28 2017 jurczy_l
//

#include	"Process.hpp"

void printe(unsigned int);
Process::Process(int id, int nb_threads)
{
  _id = id;
  _pipe_id = 0;

  for (int i = 0; i < nb_threads; i++)
    _threads.push_back(new Thread(id, _pipe_id++));
  for (int i = 0; i < nb_threads; i++)
    _threads[i]->run(routine, *_threads[i]);

  _pipe = new NamedPipe(id, -1);
  _fork = new Fork();
  if (_fork->isSon())
    { run(); }
  else
    {}
}

void		Process::run()
{
  Order		*tmp;
  size_t	shift;
  std::string	i, file, line;  

  shift = 0;

  while (getline(_pipe->_out, line))
    {
      //std::cout << "process n°" << _id << " receive " << line << std::endl;
      if (line == "exit 3")
	{
	  //std::cout << "-----Exiting process---" << _id  << "-----" << std::endl;
	  break;
	}
      std::stringstream	ss(line);
      ss >> file >> i;
      tmp = new Order(file, static_cast<Information>(std::stoi(i.c_str())));
      _queue.push(tmp);


      if (!_threads[shift]->isActive())
	_threads[shift++]->getPipe()->write_pipe(*_queue.front());
      _queue.pop();
      shift %= _threads.size();
    }

  Order avort("exit", EXIT);
  for (unsigned int i = 0; i < _threads.size(); i++)
    {
      _threads[i]->getPipe()->write_pipe(avort);
      delete _threads[i]->getPipe();      
    }
  delete _pipe;
  for (unsigned int i = 0; i < 5; i++)
    delete _threads[i];
  delete _fork;  
  exit (1);
}

Process::~Process()
{  //std::cout << "process destructor" << std::endl;
}

void		Process::setPipe(NamedPipe *data)
{ this->_pipe = data; }

int		Process::getPid() const
{ return (_fork->getPid()); }

int		Process::getId() const
{ return(_id); }

NamedPipe	*Process::getPipe() const
{ return (_pipe); }
