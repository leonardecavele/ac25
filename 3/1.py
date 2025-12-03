# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    1.py                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 09:43:40 by ldecavel          #+#    #+#              #
#    Updated: 2025/12/03 10:26:08 by ldecavel         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

def biggest_in_line(line: str) -> int:
    a = [0, 0]
    b = 0
    for i in range(0, len(line) - 1, 1):
        if int(line[i]) > a[0]:
            a[0] = int(line[i])
            a[1] = i
    for i in range(a[1] + 1, len(line), 1):
        if int(line[i]) > b:
            b = int(line[i])
    return (a[0] * 10) + b

result = 0
with open("input", "r", encoding="utf-8") as f:
    for line in f:
        result += biggest_in_line(line.rstrip("\n"))
print(result)
