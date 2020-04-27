// ======================= Diffie-Hellman Key Exchange ============
#include <iostream>
#include <fstream>

using namespace std;
// ================ Modular Exponent Psuedo Code, Source: Wikipedia ===============
// function modular_pow(base, exponent, modulus) is
// if modulus = 1 then
// return 0
// c : = 1
// for e_prime = 0 to exponent - 1 do
// c : = (c * base) mod modulus
// return c

int modular_pow(int base, int exponent, int modulus)
{
	if (modulus == 1)
	{
		return 0;
	}
	int c = 1;

	for (int e_prime = 0; e_prime < exponent; e_prime++)
	{
		c = (c * base) % modulus;
	}
	return c;
}

int isPrime(int y)// check if user input is prime
{
	ifstream prime;
	prime.open("prime.txt");// txt file including primes from 4k to 10k

	int arr[1000];
	int size_of_arr = 0;
	for (int x = 0; x < 1000; x++)
	{
		prime >> arr[x];
	}
	for (int x = 0; x < 1000; x++)
	{
		if (arr[x] > 0)
		{
			size_of_arr++;
		}
	}
	for (int x = 0; x < size_of_arr; x++)
	{
		if (y == arr[x])
		{
			return 1;
		}
	}
}
int main()
{
	int g = 0, p = 0, a = 0, b = 0;
//================ User Input ==========
	while (g < 4000 || g > 10000)// loop if NOT 4k to 10k
	{
		cout << "Please input 1st prime number from 4,000 to 10,0000: ";
		cin >> g;
		if (isPrime(g) != 1)// loop if NOT prime
		{
			cout << g << " is NOT a prime number" << endl;
			g = 0;
		}
	}
	while (p < 4000 || p > 10000)
	{
		cout << "Please input 2nd prime number from 4,000 to 10,0000: ";
		cin >> p;
		if (isPrime(p) != 1)
		{
			cout << p << " is NOT a prime number" << endl;
			p = 0;
		}
	}
	while (a < 40 || a > 100)
	{
		cout << "User A input number from 40 - 100: ";
		cin >> a;
	}
	while (b < 40 || b > 100)
	{
		cout << "User B input number from 40 - 100: ";
		cin >> b;
	}
// ============= Display User's Input ==============
	cout << "User input Prime #1: " << g << endl;
	cout << "User input Prime #2: " << p << endl;
	cout << "User A input #: " << a << endl;
	cout << "User B input #: " << b << endl;
// =================== Generate Key =============
// ========	g^a (mod p) & g^b (mod P) ===========
	
	int i = modular_pow(g, a, p);// g^a (mod p) = i
	int j = modular_pow(g, b, p);// g^b (mod p) = j

	cout << "User A security key is: " << i << endl;
	cout << "User B security key is: " << j << endl;

	cout << "User A generated: " << modular_pow(j, a, p) << endl;// j^a (mod p)
	cout << "User B generated: " << modular_pow(i, b, p) << endl;// i^b (mod p)
	
	system("pause");
}