#include "Headers.h"
int main()
{
    map<char, char> dic;
    map<char, char> revdic;

    string in = "LKOb (bwvek ove lgqkhej kwj osgx) gej g kyqj vo lvrqhkje bjlhetky lvrqjktktvu. Lvukjbkgukb gej qejbjukjz dtkw g bjk vo lwgssjuxjb dwtlw kjbk kwjte lejgktftky, kjlwutlgs (guz xvvxstux) bitssb, guz qevmsjr-bvsftux gmtstky. Lwgssjuxjb hbhgssy lvfje g uhrmje vo lgkjxvetjb, guz dwju bvsfjz, jglw ytjszb g bketux (lgssjz g osgx) dwtlw tb bhmrtkkjz kv gu vustuj blvetux bjeftlj. LKOb gej g xejgk dgy kv sjgeu g dtzj geegy vo lvrqhkje bjlhetky bitssb tu g bgoj, sjxgs juftevurjuk, guz gej wvbkjz guz qsgyjz my rguy bjlhetky xevhqb gevhuz kwj dvesz ove ohu guz qeglktlj. Ove kwtb qevmsjr, kwj osgx tb: qtlvLKO{OE3AH3ULY_4774LI5_4E3_L001_6J0659OM} abcdefghjijklmnopqrstuvwxyz";
    // string in = "g htli mevdu ov hrqjz vfje kwj sgy zvx";
    string key = "qslwrvauketcb2f3pmlinohgyd";
//  string key = "abcdefghijklmnopqrstuvwxyz";
    for (char i = 'a'; i <= 'z'; i++)
    {
        dic[i] = key[i - 'a'];
        revdic[key[i - 'a']] = i;
    }
    /*
        missing letters
        a -> 0
        c -> 0
        n -> 0
        p -> 0
        q -> 
        b -> 
        x ->
        j ->
    */
    for (int i = 0; i < key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }
    for (char i = 'A'; i <= 'Z'; i++)
    {
        dic[i] = key[i - 'A'];
        revdic[key[i - 'A']] = i;
    }
    for (auto i : dic)
    {
        cout << "dic[\'" << i.first << "\']"
             << " = "
             << "\'" << i.second << "\';" << endl;
    }
    for (int i = 0; i < in.length(); i++)
    {
        if (isalpha(in[i]))
        {
            cout << dic[in[i]];
        }
        else
            cout << in[i];
    }
    cout << endl;
    // string s = "a quick brown fox jumped over the lazy dog";
    // for (int i = 0; i < s.length(); i++)
    // {
    //     if (s[i] != ' ')
    //         cout << revdic[s[i]];
    //     else 
    //     cout<<" ";
    // }
    // cout<<endl;
}
/*
x->g show nai horaha
q rehta hai 
a -> 0
b -> s
c -> 0
d -> w
e -> r
f -> 0
g -> a
h -> u
i -> 0
j -> e
k -> t
l -> c
m -> 0
n -> 0
o -> f
p -> 0
q -> p
r -> m
s -> l
t -> i
u -> n
v -> o
w -> h
x -> g
y -> y
z -> d
*/

/*
Ifnfuxpz Wfyndzk dnpaf, oqbi d yndsf dzk abdbfwv dqn, dzk enpuyib tf bif effbwf
mnpt d ywdaa cdaf qz oiqci qb oda fzcwpafk, Qb oda d efdubqmuw acdndedfua, dzk, db
bidb bqtf, uzrzpoz bp zdbundwqaba—pm cpunaf d ynfdb xnqhf qz d acqfzbqmqc xpqzb
pm sqfo, Bifnf ofnf bop npuzk ewdcr axpba zfdn pzf flbnftqbv pm bif edcr, dzk d
wpzy pzf zfdn bif pbifn, Bif acdwfa ofnf flcffkqzywv idnk dzk ywpaav, oqbi dww bif
dxxfdndzcf pm eunzqaifk ypwk, Bif ofqyib pm bif qzafcb oda sfnv nftdnrdewf, dzk,
bdrqzy dww biqzya qzbp cpzaqkfndbqpz, Q cpuwk idnkwv ewdtf Juxqbfn mpn iqa pxqzqpz
nfaxfcbqzy qb.
*/