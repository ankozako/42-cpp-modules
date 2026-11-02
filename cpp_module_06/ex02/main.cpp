/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:12:19 by ankozako          #+#    #+#             */
/*   Updated: 2026/03/25 11:12:20 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
 
Base * generate(void);
void identify(Base* p);
void identify(Base& p);
 
int main()
{
	std::cout << "=== Test 1: Generate and identify by pointer ===" << std::endl;
	Base* obj1 = generate();
	std::cout << "Identify by pointer: ";
	identify(obj1);
	std::cout << "Identify by reference: ";
	identify(*obj1);
	delete obj1;
	
	std::cout << "\n=== Test 2: Generate and identify by pointer ===" << std::endl;
	Base* obj2 = generate();
	std::cout << "Identify by pointer: ";
	identify(obj2);
	std::cout << "Identify by reference: ";
	identify(*obj2);
	delete obj2;
	
	std::cout << "\n=== Test 3: Generate and identify by pointer ===" << std::endl;
	Base* obj3 = generate();
	std::cout << "Identify by pointer: ";
	identify(obj3);
	std::cout << "Identify by reference: ";
	identify(*obj3);
	delete obj3;
	
	std::cout << "\n=== Test 4: Manually create each type ===" << std::endl;
	
	std::cout << "Creating A:" << std::endl;
	Base* a = new A();
	std::cout << "  By pointer: ";
	identify(a);
	std::cout << "  By reference: ";
	identify(*a);
	delete a;
	
	std::cout << "Creating B:" << std::endl;
	Base* b = new B();
	std::cout << "  By pointer: ";
	identify(b);
	std::cout << "  By reference: ";
	identify(*b);
	delete b;
	
	std::cout << "Creating C:" << std::endl;
	Base* c = new C();
	std::cout << "  By pointer: ";
	identify(c);
	std::cout << "  By reference: ";
	identify(*c);
	delete c;
	
	return 0;
}
