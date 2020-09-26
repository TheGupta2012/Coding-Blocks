/*In a game of fair dice(6 sides) throw, what is the expected number of throws to
make sure that all 6 outcomes appear atleast once? Round off the ans to next integer.*/
#include<iostream>
int main() {
	float res = 0;
	for(int i = 1;i<=6;i++)
	{
		res = res + 1.0/i;
	}
	res = res*6;
	std::cout<<int(res+1);
	return 0;
}
