# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <mapapin@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 16:02:23 by user42            #+#    #+#              #
#    Updated: 2020/09/10 16:02:24 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global ft_strlen

ft_strlen:
	mov rax, 0
	jmp count_len
	
count_len:
	cmp BYTE[rdi + rax], 0
	je exit
	inc rax
	jmp count_len

exit:
	ret
