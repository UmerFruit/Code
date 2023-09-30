#include "Headers/Headers.h"
/*
    restore node
        jo node vich hua uska timestamp dekho
        uss timestamp ki file par jaake ek naye hashchain mai usko read karo
        uska tail pointer se uss node ko pakro
        uska data copy karo ek naye node pe
        uske vich wale par vo data copy kardo

*/
int main()
{
    // cout<<sizeof(size_t)<<endl;
   
    Hash_chain temp;
   // temp.writeChain();
    Hash_chain chain;
    chain.readChain();
    chain.printList();
    chain.injectDataInChain(13,"MERA NAAM CHOMU PATEL HAI!!");
    chain.printList();
    int idx = chain.checkChainConsistency();
    idx == -1? cout<<"Healthy chain"<<endl : cout<<"BREACH!"<<endl;
    // temp.printList();
    return 0;
}
