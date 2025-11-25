#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define NUM_IDEAS 100

class Brain {
	private:
		std::string ideas[NUM_IDEAS];
	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		const std::string& getIdea(int index) const;
		void setIdea(int index, const std::string& idea);
};

#endif