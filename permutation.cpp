

#include <iostream>
#include <vector>

typedef unsigned int uint;
/* 

a is a string of N letters
spec a vector of m numbers, interpreted modulo N, specifying a permutation
  a spec of the form n1 n2 n3 ...nX...., means 
           perform a n1 position cyclic right shift followed by  a swap of the first two elements followed by
		       perform a n2 position cyclic right shift followed by  a swap of the first two elements followed by

   if n is 0 the only thing happening is a swap of the first two elements
   a spec of the form n1 0 n2  can be simplified to  ( (n1+n2) mod N), so 0 only makes sense as the first or last letter in a spec.

ana is the result

*/
void mkAnagram(const std::vector<uint> spec, const std::string a, std::string & ana) {

	std::string output = a;
	
	if ((a.size() > 0) && (spec.size() > 0)){

		int outpoint = 0;
		for (int i = 0; i < spec.size(); i++) {
			outpoint = (outpoint - spec[i]);
			if(outpoint <0 ) outpoint += a.size();
			int outpoint1 = (outpoint + 1) % a.size();
			char tmp = output[outpoint];
			output[outpoint] = output[outpoint1];
			output[outpoint1] = tmp;
		}
		ana.clear();
		for (int i = 0; i < a.size(); i++) 	ana.push_back(output[ (outpoint + i) % a.size()]);

	}
}

#define LIMIT 1000000


int main()
{
    std::string res;
    std::string c("abcdefghijklmnop");
    std::vector<uint> spec1 = { 0 };
    for (int i = 0; i < LIMIT; i++)
    {
        uint carry = 1;

        mkAnagram(spec1, c, res);;
        std::cout << i << "  " << c << "   " << res << std::endl;

        for (int d = 0; d < spec1.size(); d++)
        {
            spec1[d] = (spec1[d] + carry) % c.size();
            if (spec1[d] == 0) carry = 1;
            else carry = 0;
        }
        if (carry) spec1.push_back(1);
    }
}
