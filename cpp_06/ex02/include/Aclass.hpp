#ifndef ACLASS_HPP
#define ACLASS_HPP

class Aclass {
	private:

	public:
		Aclass(void);
		Aclass(const Aclass &other);
		Aclass &operator=(const Aclass &other);
		~Aclass(void);
};

#endif // ACLASS_HPP
