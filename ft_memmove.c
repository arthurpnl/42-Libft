/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:33:25 by arpenel           #+#    #+#             */
/*   Updated: 2024/11/11 17:01:18 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || n == 0)
		return (dest);
	if (dest > src)
	{
		i = n - 1;
		while (i > 0)
		{
			((unsigned char *)dest)[i] = ((unsigned const char *)src)[i];
			i--;
		}
		((unsigned char *)dest)[i] = ((unsigned const char *)src)[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned const char *)src)[i];
			i++;
		}
	}
	return (dest);
}

#include <stdio.h>
#include <string.h>  // Pour utiliser `memcmp` et vérifier les résultats

void test_ft_memmove() {
    // Test 1 : Cas de base - pas de chevauchement
    char src1[] = "Hello, World!";
    char dest1[20];
    
    printf("Test 1: Cas de base\n");
    ft_memmove(dest1, src1, 13); // Copier tout `src1` dans `dest1`
    printf("src1 = %s\n", src1);  // Affiche la source
    printf("dest1 = %s\n", dest1);  // Affiche la destination
    printf("Result: %s\n\n", (strcmp(src1, dest1) == 0) ? "Success" : "Fail");

    // Test 2 : Cas de chevauchement - dest après src
    char src2[] = "Bonjour tout le monde";
    
    printf("Test 2: Cas de chevauchement - dest après src\n");
    ft_memmove(src2 + 7, src2, 6); // Copier "Bonjour" dans "tout le"
    printf("src2 = %s\n", src2);  // Affiche la source modifiée
    printf("Result: %s\n\n", (strcmp(src2, "Bonjour tout le monde") == 0) ? "Success" : "Fail");

    // Test 3 : Cas de chevauchement - src après dest
    char src3[] = "12345";
    char dest3[10];
    
    printf("Test 3: Cas de chevauchement - src après dest\n");
    ft_memmove(dest3, src3, 5);  // Copier "12345" dans `dest3`
    printf("src3 = %s\n", src3);  // Affiche la source
    printf("dest3 = %s\n", dest3);  // Affiche la destination
    printf("Result: %s\n\n", (strcmp(src3, dest3) == 0) ? "Success" : "Fail");

    // Test 4 : Cas où `dest` et `src` sont identiques
    char src4[] = "Exact match";
    printf("Test 4: Cas où dest et src sont identiques\n");
    ft_memmove(src4, src4, 13);  // Copie dans la même adresse mémoire
    printf("src4 = %s\n", src4);  // Affiche la source (devrait être inchangée)
    printf("Result: %s\n\n", (strcmp(src4, "Exact match") == 0) ? "Success" : "Fail");

    // Test 5 : Cas où `n` est égal à zéro
    char src5[] = "Aucun changement";
    char dest5[20];
    
    printf("Test 5: Cas où `n` est égal à zéro\n");
    ft_memmove(dest5, src5, 0);  // Ne doit rien copier
    printf("src5 = %s\n", src5);  // Affiche la source
    printf("dest5 = %s\n", dest5);  // Affiche la destination (devrait être vide)
    printf("Result: %s\n\n", (strcmp(dest5, "") == 0) ? "Success" : "Fail");
}

int main() {
    test_ft_memmove();
    return 0;
}

