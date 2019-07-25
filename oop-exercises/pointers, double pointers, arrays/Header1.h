#pragma once

//pointers to integer
/*
int a = 5;
int* pa = &a;
int** pTo_pa = &pa;

std::cout << "address of a : " << &a << outMessg1 << pa << std::endl;

std::cout << "value of a : " << a << outMessg1 << *(pa) << std::endl;

std::cout << "address of pa : " << &pa << outMessg1 << pTo_pa << std::endl;

std::cout << "value of pa : " << pa << outMessg1 << *(pTo_pa) << std::endl;
*/

//pointers to 1d integer array
/*
int* k = c;		//k is equal to c => k holds the same address as c
//std::cout << *k << std::endl;
//std::cout << *(k + 1) << std::endl;

//ToDo - need to make it the same as &c - pointer to the block of memory, pointed by c
int** pointTo_c = &k;
std::cout << "pointTo_c : " << pointTo_c << std::endl;
std::cout << (pointTo_c + 1) << std::endl;

std::cout << "c : " << c << std::endl;
std::cout << "address of c : " << &c << std::endl;
std::cout << "address of c[1] : " << &(c[1]) << std::endl;
std::cout << "value of c : " << *c << std::endl;



std::cout << "\nincrementing : " << std::endl;
std::cout << (c + 1)<< std::endl;	// + 4B
std::cout << (&c + 1) << std::endl;	// + 4B * 3
std::cout << (*pointTo_c + 1) << std::endl;
*/

//pointers to 2d integer array
/*	std::cout << "case of int** : \n" << arr1 << std::endl;
std::cout << arr1 + 1 << " <-" << std::endl;

std::cout << "case of int* (casting) : \n" << (int*)arr1 << std::endl;
std::cout << (int*)arr1 + 1 << std::endl;
std::cout << (int*)arr1 + 2 << " <-" << std::endl;

std::cout << "the same with dereference : \n" << *(arr1) << std::endl;
std::cout << *(arr1) + 1 << std::endl;

std::cout << "now for the arr2-array" << std::endl;
std::cout << "case of int** : \n" << arr2 << std::endl;
std::cout << arr2 + 1 << " <-" << std::endl;
*/