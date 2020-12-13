# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <mapapin@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 16:01:30 by user42            #+#    #+#              #
#    Updated: 2020/09/11 13:19:02 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global ft_read
	extern __errno_location

ft_read:
	mov rbx, 0
	mov rax, 0
	syscall
	cmp rax, 0
	jl error
	ret

error:
	neg rax
	mov rbx, rax
	call __errno_location
	mov [rax], rbx
	mov rax, -1
	ret
