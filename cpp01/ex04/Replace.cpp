/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:06:25 by moel-gha          #+#    #+#             */
/*   Updated: 2024/09/18 18:06:26 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2)
    : filename(filename), s1(s1), s2(s2)
{
    inputFile.open(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return;
    }

    std::string outputFilename = filename + ".replace";
    outputFile.open(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create the file " << outputFilename << std::endl;
    }
}

void Replace::performReplacement()
{
    if (!inputFile.is_open() || !outputFile.is_open()) {
        return;
    }

    std::string line;
    size_t pos;

    while (std::getline(inputFile, line))
    {
        pos = line.find(s1);
        while (pos != std::string::npos)
        {
            line.replace(pos, s1.length(), s2);
            pos = line.find(s1, pos + s2.length());
        }
        outputFile << line;
        if (!inputFile.eof()) {
            outputFile << std::endl;
        }
    }
}

Replace::~Replace() {
    if (inputFile.is_open()) {
        inputFile.close();
    }
    if (outputFile.is_open()) {
        outputFile.close();
    }
}