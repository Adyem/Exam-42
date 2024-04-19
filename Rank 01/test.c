/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvangene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:55:08 by bvangene          #+#    #+#             */
/*   Updated: 2023/07/28 09:55:11 by bvangene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Function to print the binary representation of a byte (8 bits)
void print_binary(unsigned char byte)
{
    for (int bit_pos = 7; bit_pos >= 0; bit_pos--)
    {
        char bit = (byte >> bit_pos) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main()
{
    unsigned char value = 85; // Binary: 01010101

    printf("Original value: ");
    print_binary(value); // Output: 01010101

    // Reading the 4th bit (0-indexed) in 'value'
    int fourth_bit = (value >> 3) & 1; // Result: 0
    printf("Fourth bit: %d\n", fourth_bit);

    // Changing the 6th bit (0-indexed) in 'value' to 1
    unsigned char bitmask = 1 << 5; // Shift 1 by 5 positions to the left (6th bit)
    value |= bitmask; // Set the 6th bit to 1

    printf("Modified value: ");
    print_binary(value); // Output: 11010101

    return 0;
}

