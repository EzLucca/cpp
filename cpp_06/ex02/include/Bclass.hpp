#ifndef BCLASS_HPP
#define BCLASS_HPP

class Bclass {
	private:

	public:
		Bclass(void);
		Bclass(const Bclass &other);
		Bclass &operator=(const Bclass &other);
		~Bclass(void);
};

#endif // BCLASS_HPP
