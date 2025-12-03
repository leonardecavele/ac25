# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    2.py                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 09:43:40 by ldecavel          #+#    #+#              #
#    Updated: 2025/12/03 11:53:32 by ldecavel         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

def biggest_in_line(line: str, size: int) -> int:
    result = 0
    current = 0
    for j in range(size, 0, -1):
        biggest = 0
        for i in range(current, len(line) - j + 1, 1):
            if int(line[i]) > biggest:
                biggest = int(line[i])
                current = i + 1
        result = result * 10 + biggest
    return result

result = 0
with open("input", "r", encoding="utf-8") as f:
    for line in f:
        result += biggest_in_line(line.rstrip("\n"), 12)
print(result)
