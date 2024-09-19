

#include <iostream>
#include <vector>

typedef unsigned int uint;
typedef unsigned long int u64;


#define LIMIT  362880


typedef unsigned int SomeType;



void mkPermutation(const u64 N, const std::vector<SomeType>  & inp, std::vector<SomeType> & outp)
{
    std::vector<SomeType> temp;
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

#define MAXSIMPLE 20
void mkLargePermutation(const u64 N, const std::vector<SomeType>& inp, std::vector<SomeType>& outp, uint stride = 10)
{
    std::vector<SomeType> temp = inp;
    std::vector<SomeType> temp1 = inp;
    std::vector<SomeType> buffer;
    u64  N1 = N;

    uint m = temp.size();
    if (m > MAXSIMPLE) {

        for (int i = 0; i < (4 * ((temp.size() / stride) + 1)); i++) {
            mkPermutation(N1, temp, buffer);
            for (int j = 0; j < buffer.size();j++)  temp[j] = buffer[j];
            uint o = 0;
            for (int k = stride; k < temp.size(); k++) temp1[o++] = temp[k];
            for (int k = 0; k < stride; k++) temp1[o++] = temp[k];
            temp = temp1;
            N1 = N1 + stride;
        }
        outp = temp;
    }
    else
        mkPermutation(N1, inp, outp);
}




void mkAnagram(const u64 N, const std::string& inp, std::string & outp)
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

/*

makes an anagram of string longer than 20 chars, by a set of overlapping anagrams of substrings.

*/

#define MAXSIMPLE 20
void mkLargeAnagram(const u64 N, const std::string& inp, std::string& outp, uint stride = 10)
{
    std::string temp = inp;
    std::string temp1 = inp;
    std::string buffer ;
    u64  N1 = N;

    uint m = temp.size();
    if (m > MAXSIMPLE) {

        for (int i = 0; i < (4*((temp.size() / stride) + 1)); i++) {
            mkAnagram(N1, temp, buffer);
            for (int j = 0; j < buffer.size();j++)  temp[j] = buffer[j];
            uint o = 0;
            for (int k = stride; k < temp.size(); k++) temp1[o++] = temp[k];
            for (int k = 0; k < stride; k++) temp1[o++] = temp[k];
            temp = temp1;
            N1 = N1 + stride;
        }
        outp = temp;
    }
    else             
        mkAnagram(N1, inp, outp);
}


void test( u64 count, std::string s )
{
    std::string res;
    for  (u64 i = 0; i < count; i++)  
    {
        mkAnagram(i, s, res);
        printf( "%9lu  %s \n", i, res.c_str());
		}
}

void test1( u64 no, std::string s )
{
    std::string res;
    mkLargeAnagram(no, s, res);
    printf( "%9lu  %s \n", no, res.c_str());
}

void test2(std::string s)
{
    std::string res;
    u64 t = (u64 ) 1;

    for (uint i = 0; i < 64; i++)
    {
        mkAnagram(t, s, res);
        printf("%2d  %20lu  %s \n",i, t, res.c_str());
        t |= t << 1;
    }

}


int main()
{

   std::string c0("");
   std::string c1("a");
   std::string c9("abcdefghi");
   std::string c10("abcdefghij");

   std::string c11("abcdefghijk");
   std::string c20("abcdefghijklmnoprstu");
   std::string c36("abcdefghijklmnoprstuvwxyz0123456789A");
   	
   test2(c9);

   test1(((u64)9223372036854775807 + (u64)9223372036854775800), c36);
   test1((u64)9223372036854775807 , c36);

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
