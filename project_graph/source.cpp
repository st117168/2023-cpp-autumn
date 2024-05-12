#include<iostream>

#include"CGraph.h"
#include"LinkedList.h"

int main(int argc, char* argv[])
{
	CGraph g;
	g.ReadMatrix();
	//g.ReadEdges();
	//g.ReadAdjacences();
	//g.ReadIncidenceMatrix();

	g.PrintMatrix();


	std::cout << "----IntStabList-----" << std::endl;
	g.printIntStabilityList();
	std::cout << "IntStab Number: " << g.getISN() << std::endl;
	std::cout << "----ExtStabList-----" << std::endl;
	g.printExtStabilityList();
	std::cout << "ExtStab Number: " << g.getESN() << std::endl;
	std::cout << "----KernelList------" << std::endl;
	g.printKernelList();

	return EXIT_SUCCESS;
}
