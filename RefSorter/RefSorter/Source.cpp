#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::ifstream inStream;
	std::ofstream myfile("sortedReferences.txt");
	std::string line;
	std::vector<std::string> m_references;
	inStream.open("References.txt");
	if (inStream.is_open())
	{
		std::cout << "File opened" << std::endl;
		while (std::getline(inStream, line))
		{
			while (line.length() == 0)
			{
				std::getline(inStream, line);
			}
			std::cout << line << std::endl;
			m_references.push_back(line);
			std::cout << "Total References: " << m_references.size() << std::endl;
		}

		std::sort(m_references.begin(), m_references.end());
		std::cout << "Sorted!" << std::endl;

		for (auto it = m_references.begin(); it != m_references.end(); it++)
		{
			std::cout << *it << std::endl;
		}

		if (myfile.is_open())
		{
			for (auto it = m_references.begin(); it != m_references.end(); it++)
			{
				myfile << *it << "\n" << "\n";
			}
			myfile.close();
		}
		else
		{
			std::cout << "Unable to open file";
		}

		inStream.close();
	}
	else
	{
		std::cout << "File failed to open" << std::endl;
	}
	int x;
	std::cin >> x;
	return 0;
}