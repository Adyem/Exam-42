#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock &operator=(Warlock const &other);
		Warlock(Warlock const &other);
	
	public:
		~Warlock();
		Warlock(std::string namme, std::string title);
		const std::string getName() const;
		const std::string getTitle() const;
		void setTitle(const std::string title);
		void introduce() const;
};

#endif
