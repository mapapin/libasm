# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <mapapin@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 16:01:53 by user42            #+#    #+#              #
#    Updated: 2020/09/10 16:01:55 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global ft_strcmp

ft_strcmp:
	cmp rdi, 0
	je check_null
	cmp rsi, 0
	je check_null
	jmp cmp

check_null:
	cmp rdi, rsi
	je zero
	jg one
	jmp minus_one

cmp:
	mov al, BYTE [rdi]
	mov bl, BYTE [rsi]
	cmp al, 0
	je check_ret
	cmp bl, 0
	je check_ret
	cmp al, bl
	jne check_ret
	inc rdi
	inc rsi
	jmp cmp

check_ret:
	cmp al, bl
	je zero
	jg one
	jmp minus_one

zero:
	mov rax, 0
	ret

minus_one:
	mov rax, -1
	ret

one:
	mov rax, 1
	ret
