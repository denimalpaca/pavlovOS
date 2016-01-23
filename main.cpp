#include <cmath>
#include <clibs>
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>

#define INPUT_MAX = 25

using namespace std;

void buildProbs(Ext* geptr)
{
	/* 1 ls the directory
	 * 2 check for unique file ext.s
	 * 3 allocate mem for class per ext
	 */
	int unqext = 0;
	string line;
	string ext;
	filebuf fb;
	Ext* prev;
	string ls = "ls > .exts";
	sys(ls);
	if(fb.open(".exts", ios::in))
		istream is(&fb);
	else	
		printf("Error creating .exts\n");
	while(is)
	{
		is.getline(line, 256);
		ext = strtok(line, "."); //assumes only one . in filename => does not work on hidden files
		if(!strcmp(ext, "exts"))
		{
			if(geptr == NULL)
			{
				Ext* newext = new Ext;
				geptr = newext;
				prev = geptr;
			}
			else
			{
				Ext* newext = new Ext;
				prev->next = newext;
				prev = newext;
			}
		}
	}

}

void doSomething(Ext* geptr)
{

}

void reward(Ext* geptr)
{

}

void punish(Ext* geptr)
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

void execute(string parsed, Ext* geptr)
{
	switch(string[0])
	{
		case "d":
			doSomething(geptr);
			break;
		case "r":
			reward(geptr);
			break;
		case "p":
			punish(geptr);
			break;
		default:
			printf("d: do something, r: reward, p: punish\n");
			break;
	}
}

int main(int argc, char** argv)
{
	string parsed;
	Ext* geptr = NULL;  //"global" extension class pointer
	/* initialization */
	buildProbs(geptr);
	//read and execute user input
	parsed = parse();
	execute(parsed, geptr);

	return 0;
}
