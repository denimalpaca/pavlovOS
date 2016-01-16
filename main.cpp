#include <cmath>
#include <clibs>
#include <string>
#include <cstdio>

#define INPUT_MAX = 25

using namespace std;

void doSomething()
{

}

void reward()
{

}

void punish()
{

}

string parse()
{
	//take user input and return
	string input;
	char in[INPUT_MAX];
	fgets(in, INPUT_MAX, stdin);
	input = (const) in;
	return input;
}

void execute(string parsed)
{
	switch(string[0])
	{
		case "d":
			doSomething();
			break;
		case "r":
			reward();
			break;
		case "p":
			punish();
			break;
		default:
			printf("d: do something, r: reward, p: punish\n");
			break;
	}
}

int main(int argc, char** argv)
{
	string parsed;
	/* initialization */
		//read and execute user input
		parsed = parse();
		execute(parsed);

	return 0;
}
