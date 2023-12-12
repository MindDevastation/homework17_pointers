/*
  Змініть наступну програму, замінивши звичайний вказівник на розумний вказівник std::unique_ptr
На додаткову оцінку допишіть метод для скорочення раціональних дробів
*/
#include <iostream>
#include <memory>
#include <vector>
#include <math.h>

class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;
	std::vector <int> V1;
public:

	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
	}

	int getNumerator() { return m_numerator; }
	int getDenominator() { return m_denominator; }

	void getMin() {
		V1.clear();
		int min = std::min(m_numerator, m_denominator);
		for (int k = 1; k <= std::sqrt(min); k++) {
			if (min % k == 0) {
				V1.emplace_back(k);
			}
		}
		V1.push_back(min);
	}

	void reduceTheFraction() {
			getMin();
			int max = std::max(m_numerator, m_denominator);
			for (int i = V1.size() - 1; i >= 0; i--) {
				if (max % V1.at(i) == 0) {
					if (max == m_numerator) {
						m_numerator = max / V1.at(i);
						m_denominator = m_denominator / V1.at(i);
					}
					else if (max == m_denominator) {
						m_denominator = max / V1.at(i);
						m_numerator = m_numerator / V1.at(i);
					}
				}
			}

	}

	int vectorLength() { return V1.size(); }
	int getVector(int i) { return V1.at(i); }
};





int main()
{
	std::unique_ptr<Fraction> F1 (new Fraction(49, 11711));

	std::cout << "Origingal Fraction: " << F1->getNumerator() << " / " << F1->getDenominator() << std::endl;

	F1->reduceTheFraction();

	std::cout << std::endl;

	std::cout << "Redused Fraction: " << F1->getNumerator() << " / " << F1->getDenominator() << std::endl;


	return 0;
}