/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:06:50 by moel-gha          #+#    #+#             */
/*   Updated: 2024/09/18 18:06:51 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: <log level> |DEBUG|INFO|WARNING|ERROR" << std::endl;
        return 1;
    }

    Harl harl;
    harl.harlFilter(argv[1]);
    return 0;
}
