#include <stdio.h>
#include "Tree.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>


int *GenerateArray(int count, int mod) {
	int *arr = new int[count];

	int k = 1;
	std::srand(std::time(NULL) * std::rand());
	for(int i = 0; i < count; i++){
		arr[i] = std::rand() % mod * k;
		k *= -1;
	}
	return (arr);
}



int main (void ) {

	Tree *random =		 NULL;

	// Тест 1 уничтожения из root begin
	int i = 0;
	while (i < 1000) {
		int *arrRand = GenerateArray(1000, 1000);
		CreateTree(&random, arrRand, 1000);
		while(random) {
			DeleteNode(&random, random->value);
			if (random && random->Parent)
				std::cout << "Упс!!" << std::endl;
		}
		delete arrRand;
		i++;
	}

	std::cout << GREEN "--------------------------" << std::endl;
	std::cout << "Test №1 Succsec" << std::endl;
	std::cout << "--------------------------" RESETCOLOR << std::endl;
	
	// Тест 1 уничтожения из root end
	
	// Тест 2 уничтожения случайным порядком 
	int *arrRand = GenerateArray(20, 20);
	CreateTree(&random, arrRand, 20);
	
	
	std::cout << YELLOW "--------------------------" << std::endl;
	ViewInfoAboutTree(random, random->value);
	std::cout << "--------collection--------" << std::endl;
	PrintTree(random);
	std::cout << std::endl;
	std::cout << "--------------------------" RESETCOLOR << std::endl;
	
	Tree *tmp = NULL;
	
	while (random) {
		i = std::rand() % 20;
		tmp = FoundNode(random, arrRand[i]);
		if (tmp) {
		std::cout << "Remove element == " << arrRand[i] << std::endl;
		PrintGraph(random);
		DeleteNode(&random, tmp->value);
		std::cout << YELLOW "--------------------------" RESETCOLOR << std::endl;
		}
	}

	delete arrRand;

	int j = 0;
	while (j < 1000) {
		int *arrRand = GenerateArray(1000, 1000);
		CreateTree(&random, arrRand, 1000);
		Tree *tmp = NULL;
		while (random) {

			i = std::rand() % 1000;

			tmp = FoundNode(random, arrRand[i]);

			if (tmp) {
			DeleteNode(&random, tmp->value);
			}
		}
		delete arrRand;
		j++;
	}


	std::cout << GREEN "--------------------------" << std::endl;
	std::cout << "Test №2 Succsec" << std::endl;
	std::cout << "--------------------------" RESETCOLOR << std::endl;

	return (0);

}