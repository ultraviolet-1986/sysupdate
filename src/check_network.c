/* sysupdate: A program which updates all known package managers.
 * Copyright (C) 2021 William Willis Whinn
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// ##############
// # REFERENCES #
// ##############

// <https://bbs.archlinux.org/viewtopic.php?id=213878>

// ############
// # INCLUDES #
// ############

#include "check_network.h"

// #############
// # FUNCTIONS #
// #############

int check_network()
{
	// #############
	// # VARIABLES #
	// #############

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr = { AF_INET, htons(80), inet_addr("1.1.1.1") };

	// #############
	// # KICKSTART #
	// #############

	if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) != 0) {
		return 1; /* ERROR */

	} else {
		return 0; /* SUCCESS */
	}

	close(sockfd);
}

// End of File.
