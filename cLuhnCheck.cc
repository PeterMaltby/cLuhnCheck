#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
	
	std::cout << "You Have entered " << argc << " arguments:" "\n";

	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << "\n";
	}

	if (argc != 4) {
		std::cout << "incorrect number of vars (" << argc-1 << "), 3 expected";
		return 1;
	}

	std::ifstream input(argv[1]);
	std::ofstream valid(argv[2]);
	std::ofstream invalid(argv[3]);

	std::string cardNo;

	if(input.is_open()) {
		while (getline (input,cardNo)) {
			//std::cout << "checking : " << cardNo << "\n";
			
			int nDigits = cardNo.length();
			int sum = 0;
			bool isEven = false;
			//std::cout << "no of digits = " << nDigits << "\n";

			for (int i = nDigits - 1; i>=0; i--) {
				int_fast8_t digit = cardNo[i] - '0';
				if (isEven) { digit = digit*2; }
				sum += digit / 10;
				sum += digit % 10;

				//std ::cout << "/10 = " << digit /10 << " , %10 = " << digit %10 << "\n";

				//std::cout << "digit: " << digit << "  isEven: " << isEven << " sum: " << sum << "\n";

				isEven = !isEven;
			}
			
			if (sum % 10 == 0) {
				//std::cout << "valid card!\n";
				valid << cardNo << std::endl;
			} else {
				//std::cout << "cardInvalid!\n";
				invalid << cardNo << std::endl;
			}
		}

	} else {
		std::cout << "failed to open file :" << argv[1] << "\n";
		return 1;
	}

	input.close();
	valid.close();
	invalid.close();
		
	return 0;
}
