#include <iostream>
#include <string>

struct megaphone {
	const char	*str;

	megaphone(const char *s) {
		str = s;
	}

	void	printn() {
		printf("%s\n", str);
	}
};

int	main(int argc, char *argv[]) {
	std::string	s = ""; //クラス使わずにdel呼べる？無理だったらクラス使うバージョンに変更する
	int			i = 1;
	megaphone	s = { argv };
	s.printn();

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (argv[i])
	{
		for (size_t j = 0; j < strlen(argv[i]); j++)
		{
			if (islower(argv[i][j]))
				s += (argv[i][j] - 32);
			else
				s += argv[i][j];
		}
		i++;
	}
	std::cout << s << std::endl;
	return 0;
}
