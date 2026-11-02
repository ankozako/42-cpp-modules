/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:53:15 by ankozako          #+#    #+#             */
/*   Updated: 2026/04/08 12:53:16 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "=== Subject's Test (MutantStack) ===" << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top: " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "Size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	std::cout << "Stack contents:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);
	
	std::cout << "\n=== Same Test with std::list (for comparison) ===" << std::endl;
	std::list<int> lst;
	
	lst.push_back(5);
	lst.push_back(17);
	
	std::cout << "Back: " << lst.back() << std::endl;
	
	lst.pop_back();
	
	std::cout << "Size: " << lst.size() << std::endl;
	
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	
	++lit;
	--lit;
	
	std::cout << "List contents:" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	
	std::cout << "\n=== Additional Tests ===" << std::endl;
	
	std::cout << "\n--- Test 1: Empty stack ---" << std::endl;
	MutantStack<int> empty;
	std::cout << "Empty size: " << empty.size() << std::endl;
	std::cout << "Begin == End? " << (empty.begin() == empty.end() ? "Yes" : "No") << std::endl;
	
	std::cout << "\n--- Test 2: Copy constructor ---" << std::endl;
	MutantStack<int> original;
	original.push(1);
	original.push(2);
	original.push(3);
	
	MutantStack<int> copy(original);
	std::cout << "Original size: " << original.size() << std::endl;
	std::cout << "Copy size: " << copy.size() << std::endl;
	
	std::cout << "Copy contents: ";
	for (MutantStack<int>::iterator i = copy.begin(); i != copy.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	
	std::cout << "\n--- Test 3: Assignment operator ---" << std::endl;
	MutantStack<int> assigned;
	assigned = original;
	std::cout << "Assigned size: " << assigned.size() << std::endl;
	
	std::cout << "Assigned contents: ";
	for (MutantStack<int>::iterator i = assigned.begin(); i != assigned.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	
	std::cout << "\n--- Test 4: Reverse iteration ---" << std::endl;
	MutantStack<int> rev;
	rev.push(10);
	rev.push(20);
	rev.push(30);
	
	std::cout << "Forward: ";
	for (MutantStack<int>::iterator i = rev.begin(); i != rev.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	
	std::cout << "Reverse: ";
	for (MutantStack<int>::reverse_iterator i = rev.rbegin(); i != rev.rend(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	
	std::cout << "\n--- Test 5: Different types ---" << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("!");
	
	std::cout << "String stack: ";
	for (MutantStack<std::string>::iterator i = strStack.begin(); i != strStack.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	
	std::cout << "\n--- Test 6: Standard stack operations ---" << std::endl;
	MutantStack<int> ops;
	std::cout << "Empty? " << (ops.empty() ? "Yes" : "No") << std::endl;
	
	ops.push(100);
	ops.push(200);
	ops.push(300);
	
	std::cout << "Size: " << ops.size() << std::endl;
	std::cout << "Top: " << ops.top() << std::endl;
	
	ops.pop();
	std::cout << "After pop, top: " << ops.top() << std::endl;
	std::cout << "After pop, size: " << ops.size() << std::endl;

	std::cout << "\n--- Test 7: Const iteration ---" << std::endl;
	MutantStack<int> ms;
	ms.push(10);
	ms.push(20);
	ms.push(30);
	const MutantStack<int>& constRef = ms;
	std::cout << "Const fwd iteration: ";
	for (MutantStack<int>::const_iterator it = constRef.begin(); it != constRef.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Const rev iteration: ";
	for (MutantStack<int>::const_reverse_iterator it = constRef.rbegin(); it != constRef.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}
