#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

void DecToHex(int decimal, char byteBuffer[4])
{
	int i = 3;
	while(decimal != 0 || i >= 0)
	{
		int hexDigit = decimal % 16;

		switch (hexDigit)
		{
		case 10:
			byteBuffer[i] = 'A';
			break;
		case 11:
			byteBuffer[i] = 'B';
			break;
		case 12:
			byteBuffer[i] = 'C';
			break;
		case 13:
			byteBuffer[i] = 'D';
			break;
		case 14:
			byteBuffer[i] = 'E';
			break;
		case 15:
			byteBuffer[i] = 'F';
			break;
		default:
			byteBuffer[i] = hexDigit + '0';
			break;
		}


		decimal /= 16;
		i--;
	}
}

int main()
{
	int leftOperand, rightOperand, result = 0;
	char action = '0';

	while (action == '0')
	{ cout<< " operand_1 action operand_2"<<endl;
		cin >> leftOperand >> action >> rightOperand;

		switch (action)
		{
		case '&':
			result = leftOperand & rightOperand;
			break;
		case '^':
			result = leftOperand ^ rightOperand;
			break;
		case '|':
			result = leftOperand | rightOperand;
			break;
		default:
			action = '0';
			cout << "Error, please try again" << endl;
		}
	}

	char leftOperandHex[4];
	char rightOperandHex[4];
	char resultHex[4];

	DecToHex(leftOperand, leftOperandHex);
	DecToHex(rightOperand, rightOperandHex);
	DecToHex(result, resultHex);

	for (int i = 0; i < 4; i++)
	{
		cout << leftOperandHex[i];

		if (i == 1) cout << " ";
	}

	cout << " " << action << " ";

	for (int i = 0; i < 4; i++)
	{
		cout << rightOperandHex[i];

		if (i == 1) cout << " ";
	}

	cout << " = ";

	for (int i = 0; i < 4; i++)
	{
		cout << resultHex[i];

		if (i == 1) cout << " ";
	}
	return 0;
}

