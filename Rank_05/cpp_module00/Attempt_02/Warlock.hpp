#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <string>

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock &operator=(Warlock &other);
		Warlock(Warlock &other);

	public:
		Warlock(std::string name, std::string title);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;
};

#endif
