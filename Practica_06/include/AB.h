#ifndef AB_H
#define AB_H

#include <cstdio>
#include <ostream>
#include "./nodoB.h"

template<class Key>
class AB {

public:
	virtual bool insert(const Key& k) = 0;
	virtual void seach(const Key& k) const = 0;
	virtual void remove(const Key& k) = 0;
	virtual void showAB() = 0;
	void inorden() const;
	// std::ostream& operator<<(ostream& os, const Date& dt);
private:
	NodoB<Key>* root_;
};

// template<class Key>
// std::ostream& operator<<(std::ostream& os, const Key& dt)
// {
//     // os << dt.mo << '/' << dt.da << '/' << dt.yr;
//     return os;
// }


#endif //AB_H