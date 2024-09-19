

#include <iostream>
#include <vector>

typedef unsigned int uint;
typedef unsigned long int u64;


#define LIMIT  362880



void mkAnagram1(const u64 N, const std::string& inp, std::string & outp)
{
    std::string temp;
    u64  Ntemp = N;
    uint sz = inp.size();
    uint outindex = 0;

    if (sz > 20) sz = 20;

    outp.clear();
    switch (sz)
    {
    case 0: break;

    case 1: outp.push_back(inp[0]); break;

    default: 
			outp.push_back(inp[0]);
			temp.clear();
			outindex = 1;
			do {
				u64 s = (Ntemp % (outp.size() + 1));
				Ntemp = Ntemp / (outp.size() + 1);
				uint tsize = outp.size();
				for (int r = 0; r < tsize; r++) {
					if (r == s) { temp.push_back(inp[outindex]); }
					temp.push_back(outp[r]);
				}
				if (temp.size() == tsize) temp.push_back(inp[outindex]);

				outp = temp;
				outindex++;
				temp.clear();
			} while (outp.size() < sz);
		break;
    }

}

void test( u64 count, std::string s )
{
    std::string res;
    for  (u64 i = 0; i < count; i++)  
    {
        mkAnagram1(i, s, res);
        printf( "%9lu  %s \n", i, res.c_str());
		}
}

void test1( u64 no, std::string s )
{
    std::string res;
    mkAnagram1(no, s, res);
    printf( "%9lu  %s \n", no, res.c_str());
}

int main()
{

   std::string c0("");
   std::string c1("a");
   std::string c9("abcdefghi");
   std::string c10("abcdefghij");

   std::string c11("abcdefghijk");
   std::string c20("abcdefghijklmnoprstu");

   test1(19067857, c11);
   test1(19087857, c11);
   test1( 9167857, c11);
   test1(519067857, c20);
   test1(419087857, c20);
   test1(39167857, c20);
   test1(1519067857, c20);
   test1(1419087857, c20);
   test1(139167857, c20);
   test1(21519067857, c20);
   test1(31419087857, c20);
   test1(((unsigned long int )9223372036854775807 + (unsigned long int ) 9223372036854775800), c20);
   test1(9223372036854775807, c20);
   test1(8223372036854775807, c20);
   test1(7223372036854775807, c20);
   test1(6223372036854775807, c20);
   test1(5223372036854775807, c20);
   test1(4223372036854775807, c20);
   test1(3223372036854775807, c20);
   test1(2223372036854775807, c20);
   test1(1223372036854775807, c20);
   test1(471586864139167857, c20);
   test1(371586864139167857, c20);
   test1(271586864139167857, c20);
   test1(171586864139167857, c20);
   //test(11*10*LIMIT,c11);

}
