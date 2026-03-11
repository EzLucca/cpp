#ifndef CCLASS_HPP
#define CCLASS_HPP

class Cclass {
	private:

	public:
		Cclass(void);
		Cclass(const Cclass &other);
		Cclass &operator=(const Cclass &other);
		~Cclass(void);
};

#endif // CCLASS_HPP
