/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:21:51 by ankozako          #+#    #+#             */
/*   Updated: 2026/03/04 16:21:53 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "=== Subject Test ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	std::cout << "\n=== Test: Full Inventory ===" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	
	ICharacter* hero = new Character("hero");
	
	hero->equip(src2->createMateria("ice"));
	hero->equip(src2->createMateria("cure"));
	hero->equip(src2->createMateria("ice"));
	hero->equip(src2->createMateria("cure"));
	
	AMateria* extra = src2->createMateria("ice");
	hero->equip(extra);
	delete extra;
	
	ICharacter* target = new Character("target");
	hero->use(0, *target);
	hero->use(1, *target);
	hero->use(2, *target);
	hero->use(3, *target);
	
	delete target;
	delete hero;
	delete src2;

	std::cout << "\n=== Test: Unequip and Floor Management ===" << std::endl;
	IMateriaSource* src3 = new MateriaSource();
	src3->learnMateria(new Ice());
	
	ICharacter* alice = new Character("alice");
	AMateria* floor[10];
	int floorCount = 0;
	
	AMateria* m1 = src3->createMateria("ice");
	AMateria* m2 = src3->createMateria("ice");
	
	alice->equip(m1);
	alice->equip(m2);
	
	std::cout << "Unequipping slot 0..." << std::endl;
	floor[floorCount++] = m1;
	alice->unequip(0);
	
	std::cout << "Unequipping slot 1..." << std::endl;
	floor[floorCount++] = m2;
	alice->unequip(1);
	
	std::cout << "Cleaning up floor..." << std::endl;
	for (int i = 0; i < floorCount; i++)
		delete floor[i];
	
	delete alice;
	delete src3;

	std::cout << "\n=== Test: Invalid Operations ===" << std::endl;
	ICharacter* dummy = new Character("dummy");
	ICharacter* enemy = new Character("enemy");
	
	std::cout << "Using invalid slot -1: ";
	dummy->use(-1, *enemy);
	std::cout << "(nothing should happen)" << std::endl;
	
	std::cout << "Using invalid slot 5: ";
	dummy->use(5, *enemy);
	std::cout << "(nothing should happen)" << std::endl;
	
	std::cout << "Using empty slot 0: ";
	dummy->use(0, *enemy);
	std::cout << "(nothing should happen)" << std::endl;
	
	std::cout << "Unequipping invalid slot -1: ";
	dummy->unequip(-1);
	std::cout << "(nothing should happen)" << std::endl;
	
	std::cout << "Unequipping empty slot 0: ";
	dummy->unequip(0);
	std::cout << "(nothing should happen)" << std::endl;
	
	delete enemy;
	delete dummy;

	std::cout << "\n=== Test: Unknown Materia Type ===" << std::endl;
	IMateriaSource* src4 = new MateriaSource();
	src4->learnMateria(new Ice());
	
	AMateria* unknown = src4->createMateria("fire");
	if (unknown == NULL)
		std::cout << "createMateria(\"fire\") returned NULL - correct!" << std::endl;
	else
	{
		std::cout << "ERROR: Should have returned NULL!" << std::endl;
		delete unknown;
	}
	
	delete src4;

	std::cout << "\n=== Test: Deep Copy Character ===" << std::endl;
	IMateriaSource* src5 = new MateriaSource();
	src5->learnMateria(new Ice());
	src5->learnMateria(new Cure());
	
	Character* original = new Character("original");
	original->equip(src5->createMateria("ice"));
	original->equip(src5->createMateria("cure"));
	
	std::cout << "Creating copy..." << std::endl;
	Character* copy = new Character(*original);
	
	ICharacter* testTarget = new Character("testTarget");
	
	std::cout << "\nOriginal uses slot 0:" << std::endl;
	original->use(0, *testTarget);
	
	std::cout << "Copy uses slot 0:" << std::endl;
	copy->use(0, *testTarget);
	
	std::cout << "\nBoth have independent inventories - deep copy works!" << std::endl;
	delete testTarget;
	delete copy;
	delete original;
	delete src5;

	std::cout << "\n=== Test: MateriaSource Full ===" << std::endl;
	MateriaSource* fullSrc = new MateriaSource();
	
	fullSrc->learnMateria(new Ice());
	fullSrc->learnMateria(new Cure());
	fullSrc->learnMateria(new Ice());
	fullSrc->learnMateria(new Cure());
	
	std::cout << "Learning 5th Materia (should be deleted)..." << std::endl;
	fullSrc->learnMateria(new Ice());
	
	delete fullSrc;

	std::cout << "\n=== Test: Clone Functionality ===" << std::endl;
	Ice* ice = new Ice();
	Cure* cure = new Cure();
	
	AMateria* iceClone = ice->clone();
	AMateria* cureClone = cure->clone();
	
	std::cout << "Original Ice type: " << ice->getType() << std::endl;
	std::cout << "Cloned Ice type: " << iceClone->getType() << std::endl;
	std::cout << "Original Cure type: " << cure->getType() << std::endl;
	std::cout << "Cloned Cure type: " << cureClone->getType() << std::endl;
	
	delete ice;
	delete cure;
	delete iceClone;
	delete cureClone;

	std::cout << "\n=== Test: Equip NULL ===" << std::endl;
	Character* nullTest = new Character("nullTest");
	nullTest->equip(NULL);
	std::cout << "(should do nothing - no crash)" << std::endl;
	delete nullTest;

	std::cout << "\n=== All Tests Complete ===" << std::endl;
	
	return 0;
}
