/* Custom manipulators.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#ifndef __IOMANIP_HPP__
#define __IOMANIP_HPP__

#include <iostream>

inline std::ostream& endm(std::ostream& stream){
	return stream << "[eol]\n";
}


class Support {
private:
	std::ostream& stream_;
public:
	Support(std::ostream &stream) : stream_(stream){}

	template <class T>
	std::ostream& operator << (const T& var) {
		stream_ << '[' << var << ']';
		return stream_;
	}
};

class Squares {

};

inline Support operator <<(std::ostream& os, Squares) {
	return Support(os);
}
const Squares squares;

class Support1 {
public:
	std::ostream& stream_;
	Support1(std::ostream& stream) : stream_(stream) {}
	class Support2 {
	public:
		std::ostream& stream_;
		int i;
		double d;
		std::string s;

		Support2(std::ostream& stream, const int & var ) : stream_(stream), i(var) {}
		Support2(std::ostream& stream, const double var) : stream_(stream), d(var) {}
		Support2(std::ostream& stream, const std::string& var) : stream_(stream), s(var) {}
		// Можете подсказать, почему не работает без const в предыдущей строчке?
		// Выдает ошибку при компиляции <function - style - cast> : невозможно преобразовать "initializer list" в "Support1::Support2"	
		
		std::ostream& operator << (const int& var) {
			stream_ << i+ var;
			return stream_;
		}
		std::ostream& operator << (const double& var) {
			stream_ << d + var;
			return stream_;
		}
		std::ostream& operator << (const std::string& var) {
			stream_ << s + var;
			return stream_;
		}
	};

	template <class T>
	struct Support2 operator <<  (T const& var) {
		return Support2(stream_,var);
	}
};


class Add {

};


inline Support1 operator << (std::ostream& os, const Add) {
	return Support1(os);
}

const Add add;



#endif // __IOMANIP_HPP__
