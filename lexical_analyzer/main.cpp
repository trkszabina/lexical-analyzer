
#include "analyzer.h"
#include <fstream>
#include <iostream>


int main() {
    std::ifstream inputfile;
    inputfile.open("inputtext.txt");
    LexicalAnalyzer analyze(inputfile);
	try 
	{
		analyze.run_analyzer();
	}
	catch (const std::exception&)
	{
		std::cout << "error";
	}
    return 0;
}