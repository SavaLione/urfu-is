#include "cipher/hill.h"

hill::hill()
{
}

hill::~hill()
{
}

int hill::_mod_inverse(int a, int m)
{
	a = a % m;
	for(int x = -m; x < m; x++)
	{
		if((a * x) % m == 1)
		{
			return x;
		}
	}
	return 0; // inverse not found
}

void hill::_get_cofactor(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &temp, int p, int q, int n)
{
	int i = 0, j = 0;
	for(int row = 0; row < n; row++)
	{
		for(int col = 0; col < n; col++)
		{
			if(row != p && col != q)
			{
				temp[i][j++] = a[row][col];
				if(j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

int hill::_determinant(std::vector<std::vector<int>> &a, int n, int N)
{
	int D = 0;
	if(n == 1)
	{
		return a[0][0];
	}
	std::vector<std::vector<int>> temp(N, std::vector<int>(N));
	int sign = 1;
	for(int f = 0; f < n; f++)
	{
		_get_cofactor(a, temp, 0, f, n);
		D += sign * a[0][f] * _determinant(temp, n - 1, N);
		sign = -sign;
	}
	return D;
}

void hill::_adjoint(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &adj, int N)
{
	if(N == 1)
	{
		adj[0][0] = 1;
		return;
	}
	int sign = 1;
	std::vector<std::vector<int>> temp(N, std::vector<int>(N));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			_get_cofactor(a, temp, i, j, N);
			sign	  = ((i + j) % 2 == 0) ? 1 : -1;
			adj[j][i] = (sign) * (_determinant(temp, N - 1, N));
		}
	}
}

bool hill::_inverse(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &inv, int N)
{
	int det = _determinant(a, N, N);
	if(det == 0)
	{
		std::cout << "Inverse does not exist" << std::endl;
		return false;
	}
	// int invDet = _mod_inverse(det, 26);
	int invDet = _mod_inverse(det, _alphabet.size());
	// std::cout << det % 26 << ' ' << invDet << '\n';
	std::cout << det % _alphabet.size() << ' ' << invDet << '\n';
	std::vector<std::vector<int>> adj(N, std::vector<int>(N));
	_adjoint(a, adj, N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// inv[i][j] = (adj[i][j] * invDet) % 26;
			inv[i][j] = (adj[i][j] * invDet) % _alphabet.size();
		}
	}
	return true;
}

void hill::decryption()
{
	int x, y, i, j, k, n;
	std::cout << "Enter the size of key matrix\n";
	std::cin >> n;
	std::cout << "Enter the key matrix\n";
	std::vector<std::vector<int>> a(n, std::vector<int>(n));
	std::vector<std::vector<int>> adj(n, std::vector<int>(n));
	std::vector<std::vector<int>> inv(n, std::vector<int>(n));
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			std::cin >> a[i][j];
		}
	}
	if(_inverse(a, inv, n))
	{
		std::cout << "Inverse exist\n";
	}
	std::cout << "Enter the message to decrypt\n";
	std::string s;
	std::cin >> s;
	k = 0;
	std::string ans;
	while(k < s.size())
	{
		for(i = 0; i < n; i++)
		{
			int sum	 = 0;
			int temp = k;
			for(j = 0; j < n; j++)
			{
				// sum += ((inv[i][j] + 26) % 26 * (s[temp++] - 'a') % 26) % 26;
				// sum = sum % 26;
				sum += ((inv[i][j] + _alphabet.size()) % _alphabet.size() * _get_num(s[temp++]) % _alphabet.size() % _alphabet.size());
				sum = sum % _alphabet.size();
			}
			// ans += (sum + 'a');
			ans += _alphabet[sum];
		}
		k += n;
	}
	//ans+='\0';
	int f = ans.size() - 1;
	while(ans[f] == 'x')
	{
		f--;
	}
	for(i = 0; i <= f; i++)
	{
		std::cout << ans[i];
	}
	std::cout << '\n';
}

int hill::_get_num(char const &ch)
{
	int ret = 0;
	for(int i = 0; i < _alphabet.size(); i++)
	{
		if(_alphabet[i] == ch)
		{
			return i;
		}
	}

	return ret;
}

void hill::encryption()
{
	int x, y, i, j, k, n;
	std::cout << "Enter the size of key matrix\n";
	std::cin >> n;
	std::cout << "Enter the key matrix\n";
	int a[n][n];
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			std::cin >> a[i][j];
		}
	}
	std::cout << "Enter the message to encrypt\n";
	std::string s;
	std::cin >> s;
	int temp = (n - s.size() % n) % n;
	for(i = 0; i < temp; i++)
	{
		s += 'x';
	}
	k				= 0;
	std::string ans = "";
	while(k < s.size())
	{
		for(i = 0; i < n; i++)
		{
			int sum	 = 0;
			int temp = k;
			for(j = 0; j < n; j++)
			{
				// sum += (a[i][j] % 26 * (s[temp++] - 'a') % 26) % 26;
				// sum = sum % 26;
				sum += (a[i][j] % _alphabet.size() * _get_num(s[temp++]) % _alphabet.size() % _alphabet.size());
				sum = sum % _alphabet.size();
			}
			// ans += (sum + 'a');
			ans += _alphabet[sum];
		}
		k += n;
	}
	std::cout << ans << '\n';
}