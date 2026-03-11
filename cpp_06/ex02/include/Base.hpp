#ifndef BASE_HPP
#define BASE_HPP

class Base {
	private:

	public:
		Base(void);
		Base(const Base &other);
		Base &operator=(const Base &other);
		virtual ~Base(void);
};

#endif // BASE_HPP
