#include<iostream>

#include"CGraph.h"
#include"LinkedList.h"

int main(int argc, char* argv[])
{
	CGraph g;
	g.ReadEdges();
	g.PrintMatrix();
	std::cout << "----IntStabList-----" << std::endl;
	g.printIntStabilityList();
	std::cout << "IntStab Number: " << g.getISN() << std::endl;
	std::cout << "----ExtStabList-----" << std::endl;
	g.printExtStabilityList();
	std::cout << "ExtStab Number: " << g.getESN() << std::endl;
	std::cout << "----KernelList------" << std::endl;
	g.printKernelList();
	//LinkedList list;
	//list.pushtail(1);
	//list.pushtail(2);
	//list.pushtail(0);
	//list.pushtail(11);
	//list.pushtail(0);
	//std::cout << list;
	return EXIT_SUCCESS;
}
