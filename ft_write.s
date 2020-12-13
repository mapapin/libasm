# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <mapapin@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 16:02:34 by user42            #+#    #+#              #
#    Updated: 2020/09/11 15:58:42 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global ft_write
	extern __errno_location

ft_write:
	mov rbx, 0
	mov rax, 1
	syscall
	cmp rax, 0
	jl error
	jmp exit

error:
	neg rax
	mov rbx, rax
	call __errno_location
	mov [rax], rbx
	mov rax, -1
	ret
	
exit:
	ret
