#ifndef _FILE_H_
#define _FILE_H_

#include <fstream>
#include <string>
#include <iostream>

class File
{
	private:
		std::string	name_;
		std::string	name_new_;
		std::string	s_original_;
		std::string	s_new_;
		std::string	replaceLine(std::string line);
		bool		isValidIn(std::ifstream &ifs);
		bool		isValidOut(std::ofstream &ofs);
		bool		isValidArg();
	public:
		File(char *argv[]);
		~File();
		void		replace();
};

#endif
