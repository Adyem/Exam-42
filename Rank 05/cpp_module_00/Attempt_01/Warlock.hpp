#ifndef NOODLES_H
# define NOODLES_H

#include <string>
#include <iostream>

class Warlock 
{
	private:
		std::string name;
		std::string	title;
		Warlock();
		Warlock &operator=(Warlock const &other);
		Warlock(Warlock const &Other);

	public:
		Warlock(std::string name, std::string title);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const & str);
		void introduce() const;
};

#endif
