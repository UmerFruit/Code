#include "Headers.h"
int main()
{
    map<char, char> dic;
    string key = "abcdefghijklmnopqrstuvwxyz";
    for (char i = 'a'; i <= 'z'; i++)
    {
        dic[i] = key[i - 'a'];
    }
    string in = "fnjdjjzqsfsjpjdxwmfnjdcjwwjsfxhwqsnjynqensknmmwkmuvafjdsjkadqftkmuvjfqfqmgsqgkwayqgekthjdvxfdqmfxgyaskthjdknxwwjgejfnjsjkmuvjfqfqmgslmkasvdquxdqwtmgstsfjusxyuqgqsfdxfqmglagyxujgfxwscnqknxdjpjdtasjlawxgyuxdojfxhwjsoqwwsnmcjpjdcjhjwqjpjfnjvdmvjdvadvmsjmlxnqensknmmwkmuvafjdsjkadqftkmuvjfqfqmgqsgmfmgwtfmfjxknpxwaxhwjsoqwwshafxwsmfmejfsfayjgfsqgfjdjsfjyqgxgyjzkqfjyxhmafkmuvafjdskqjgkjyjljgsqpjkmuvjfqfqmgsxdjmlfjgwxhmdqmasxllxqdsxgykmujymcgfmdaggqgeknjkowqsfsxgyjzjkafqgekmglqeskdqvfsmlljgsjmgfnjmfnjdnxgyqsnjxpqwtlmkasjymgjzvwmdxfqmgxgyquvdmpqsxfqmgxgymlfjgnxsjwjujgfsmlvwxtcjhjwqjpjxkmuvjfqfqmgfmaknqgemgfnjmlljgsqpjjwjujgfsmlkmuvafjdsjkadqftqsfnjdjlmdjxhjffjdpjnqkwjlmdfjknjpxgejwqsufmsfayjgfsqgxujdqkxgnqensknmmwsladfnjdcjhjwqjpjfnxfxgagyjdsfxgyqgemlmlljgsqpjfjkngqiajsqsjssjgfqxwlmdumagfqgexgjlljkfqpjyjljgsjxgyfnxffnjfmmwsxgykmglqeadxfqmglmkasjgkmagfjdjyqgyjljgsqpjkmuvjfqfqmgsymjsgmfwjxysfayjgfsfmogmcfnjqdjgjutxsjlljkfqpjwtxsfjxknqgefnjufmxkfqpjwtfnqgowqojxgxffxkojdvqkmkflqsxgmlljgsqpjwtmdqjgfjynqensknmmwkmuvafjdsjkadqftkmuvjfqfqmgfnxfsjjosfmejgjdxfjqgfjdjsfqgkmuvafjdskqjgkjxumgenqensknmmwjdsfjxknqgefnjujgmaenxhmafkmuvafjdsjkadqftfmvqiajfnjqdkadqmsqftumfqpxfqgefnjufmjzvwmdjmgfnjqdmcgxgyjgxhwqgefnjufmhjffjdyjljgyfnjqduxknqgjsfnjlwxeqsvqkmKFL{G6D4U_4G41T515_15_73Y10A5_42JX1770}";
    // picoctf = vqkmKFL 
    dic['v'] = 'p';
    dic['q'] = 'i';
    dic['k'] = 'c';
    dic['m'] = 'o';
    dic['K'] = 'C';
    dic['k'] = 'c';
    dic['f'] = 't';
    dic['F'] = 'T';
    dic['L'] = 'F';
    dic['l'] = 'f';




    // for (int i = 0; i < key.length(); i++)
    // {
    //     key[i] = toupper(key[i]);
    // }
    // for(char i = 'A';i<='Z';i++)
    // {
    //     dic[i] = key[i];
    // }
    // for(auto i: dic)
    // {
    //     cout<<"dic[\'"<<i.first<<"\']"<<" = "<<"\'"<<i.second<<"\';"<<endl;
    // }
    for(int i =0;i<in.length();i++)
    {
        if(isalpha(in[i]))
        {
            cout<<dic[in[i]];
        }
        else
        {
            cout<<in[i];
        }
    }
    cout<<endl;
}