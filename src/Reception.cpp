//
// Orders.cpp for Project-Master in /home/louis/Documents/cpp_plazza/src
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 10:45:13 2017 jurczy_l
// Last update Fri Apr 28 15:11:55 2017 augustin marmus
//

#include	"Reception.hpp"
#include	<string.h>

Reception::Reception()
{
  // std::cout << "------------------------------------------------" << std::endl;
  // std::cout << "----------OUVERTURE--DE--LA--PIZZERIA-----------" << std::endl;
  // std::cout << "----------------------------------(sans pizza)--" << std::endl;
  _id = 0;
}

Reception::~Reception()
{
  // std::cout << "------------------------------------------------" << std::endl;
  // std::cout << "----------FERMETURE--DE--LA--PIZZERIA-----------" << std::endl;
  // std::cout << "----------------------------------(sans pizza)--" << std::endl;
}

void		Reception::setNbThreads(int nb)
{ this->nb_threads = nb; }

int		Reception::getNbThreads() const
{ return(nb_threads); }

void		Reception::parse_order(std::string token)
{
  std::vector<std::string>	tab;
  std::istringstream		iss(token);
  Information			type = NONE;

  for(std::string str; iss >> token;)
    tab.push_back(token);
  if (tab.size() > 1)
    {
      if (tab[tab.size() - 1] == "PHONE_NUMBER")
	type = PHONE_NUMBER;
      else if (tab[tab.size() - 1] == "EMAIL_ADDRESS")
	type = EMAIL_ADDRESS;
      else if (tab[tab.size() - 1] == "IP_ADDRESS")
	type = IP_ADDRESS;
    }
  if (type != NONE)
    for (size_t i = 0; i < tab.size() - 1; i++)
      {
	Order *unit = new Order(tab[i], type);
	// std::cout << "+" << type << ";"<< tab[i] << std::endl;
	orders.push(unit);
      }
}

void		Reception::send_order(Process *proc, Order *data)
{
  proc->getPipe()->write_pipe(*data);
}

Process		*Reception::create_process()
{
  pid_t		pid = 1;
  Process	*unit;
  
  unit = new Process(_id, nb_threads);
  _id++;
  if (pid == -1)
    exit(1);
  else if (pid == 0)
    {}
  else
    {
      _processes.push_back(unit);
    }
  return (NULL);
}

void		Reception::send_exit(Process *proc)
{
  int		fifo_client;

  if ((fifo_client = open(proc->getPipe()->_out_str.c_str(),O_RDWR)) == -1)
   exit (50);
  //  std::cout << "Killing process: " << proc->getId() <<" ("<< proc->getPid()<< " pid)."<<std::endl;
  //write(fifo_client, "exit\n", 5);
  Order	tmp("exit", EXIT);
  proc->getPipe()->write_pipe(tmp);
  // // for (std::vector<Process *>::iterator it = _processes.begin(); it != _processes.end(); it++)
  // //   if ((*it)->getId() == proc->getId())
  // //     {
  // // 	delete (*it);
  // // 	_processes.erase(it);
  // // 	break;
  // //     }
}

void		Reception::read_orders()
{
  size_t			pos = 0;
  std::string			token = "";
  int				status;

  create_process();
  for (std::string line; std::getline(std::cin, line);)
    {
      while ((pos = line.find(';')) != std::string::npos)
	{
	  token = line.substr(0, pos);
	  line.erase(0, pos + 1);
	  parse_order(token);
	}
      parse_order(line);

      //dépile toute la queue
      while (!orders.empty())
	{
	  send_order(_processes[0], orders.front());
	  orders.pop();
	}
    }

  while (_processes.size() > 0)
    {
      send_exit(_processes[0]);
      waitpid(_processes[0]->getPid(), &status, 0);
      _processes.erase(_processes.begin());      
    }
  //std::cout << "exit reception" << std::endl;
}
