# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <mapapin@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 16:02:01 by user42            #+#    #+#              #
#    Updated: 2020/09/10 16:03:38 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global ft_strcpy

ft_strcpy:
	cmp rsi, 0
	je null
	mov r8, 0
	jmp cpy

cpy:
	mov al, BYTE [rsi + r8]
	mov BYTE [rdi + r8], al
	cmp al, 0
	je exit
	inc r8
	jmp cpy

null:
	mov rax, 0
	ret
exit:
	mov rax, rdi
	ret
