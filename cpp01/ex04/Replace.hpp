/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:06:28 by moel-gha          #+#    #+#             */
/*   Updated: 2024/09/18 18:06:29 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>


class Replace {
public:
    Replace(std::string filename, std::string s1, std::string s2);
    void performReplacement();
    ~Replace(void);

private:
    std::string filename;
    std::string s1;
    std::string s2;
    std::ifstream inputFile;
    std::ofstream outputFile;
};

#endif