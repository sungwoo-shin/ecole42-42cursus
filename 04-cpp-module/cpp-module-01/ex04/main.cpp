/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:57:17 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 17:54:44 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Invalid arguments" << std::endl
		<< "Usage: [File name] [String1 for SRC] [String2 for DST]"
		<< std::endl;
		return (1);
	}
	std::string fname = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (fname.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Error: Invalid arguments" << std::endl
		<< "Check File name or String" << std::endl;
		return (1);
	}

	std::ifstream fin(fname);
	if (fin.fail())
	{
		std::cout << "Error : Cannot open the file" << std::endl;
		return (1);
	}
	std::ofstream fout(fname + ".replace");
	if (fout.fail())
	{
		std::cout << "Error : Cannot open the file" << std::endl;
		return (1);
	}

	std::string line;
	std::string::size_type pos;
	while (getline(fin, line))
	{
		while (1)
		{
			pos = line.find(s1);
			if (pos == std::string::npos)
				break ;
			line.replace(pos, s1.length(), s2);
		}
		fout << line;
		if (fin.eof() == false)
			fout << '\n';
	}
	return (0);
}
