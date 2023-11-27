/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:23:38 by gcros             #+#    #+#             */
/*   Updated: 2023/11/26 21:13:38 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHMUP_H
# define FT_SHMUP_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include <csignal>
#include <time.h>

#include "Ship.h"

#define SIZE_X 100
#define SIZE_Y 100

using namespace std;

void resetTerminal();

int kbhit(void);

#endif
