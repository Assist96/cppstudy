#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>
#include<string>
#include<array>
#include<ctime>
#include<cstdlib>
using namespace std;
// int main(){
//     int a[6]={27,210,12,47,109,83};
//     vector<int,allocator<int>>vi(a,a+6);
//     cout<<count_if(vi.begin(),vi.end(),
//         not1(bind2nd(less<int>(),40)));
//         return 0;
// }

 
long get_a_target_long(){
    long target=0;
    cout<<"target(0~"<<RAND_MAX<<"):";
    cin>>target;
    return target;
}
string get_a_target_string(){
   long target=0;
    char buf[10];
	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}
int compareLongs(const void* a,const void*b){
    return (*(long*)a-*(long*)b);
}
int compareStrings(const void *a,const void*b){
    if (*(string *)a>*(string *)b){
        return 1;
    }
    else if (*(string*)a<*(string*)b){
        return -1;
    }
    else
    return 0;
}
const long ASIZE=500000;
#include<array>
#include<iostream>
#include<ctime>
#include<cstdlib>
namespace sample01
{
void test_array(){
    srand(time(NULL));
    cout<<"\ntest_array()........\n";
    array<long,ASIZE> c;
    clock_t timeStart=clock();
    for (long i=0;i<ASIZE;++i){
        c[i]=rand();
    }
    cout<<"milli-seconds:"<<(clock()-timeStart)<<endl;
    cout<<"array.size()="<<c.size()<<endl;
    cout<<"array.front()="<<c.front()<<endl;
    cout<<"array.back()="<<c.back()<<endl;
    cout<<"array.data()="<<c.data()<<endl;

    long target=get_a_target_long();
    timeStart=clock();
    qsort(c.data(),ASIZE,sizeof(long),compareLongs);
    long * pItem=(long*)bsearch(&target,(c.data()),ASIZE,sizeof(long),compareLongs);
    cout<<"qSort()+bsearch() milli-seconds:"<<(clock()-timeStart)<<endl;
    if(pItem!=NULL){
        cout<<"found,"<<*pItem<<endl;
    }
    else
    cout<<"not found!"<<endl;
}

}

#include <vector>
#include<stdexcept>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>
namespace sample02
{
    void test_vector(long &value){
        cout<<"\ntest_vector()\n";
        vector<string> c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i=0;i<value;++i){
            try{
                    snprintf(buf,10,"%d",rand());
                    c.push_back(string(buf));
            }
            catch(exception& p){
                cout<<"i="<<i<<" "<<p.what()<<endl;
                abort();
            }
        }
        cout<<"Microseconds:"<< (clock()-timeStart)<<"(CLOCKS_PER_SEC:"<<CLOCKS_PER_SEC<<")"<<endl;
    cout<<"vector.size()="<<c.size()<<endl;
    cout<<"vector.front()="<<c.front()<<endl;
    cout<<"vector.back()="<<c.back()<<endl;
    cout<<"vector.data()="<<c.data()<<endl;
    cout<<"vector.capacity()="<<c.capacity()<<endl;
    string target=get_a_target_string();

    {
        timeStart=clock();
        auto pItem=::find(c.begin(),c.end(),target);
        cout<<"::find(),microseconds:"<<(clock()-timeStart)<<endl;
        if(pItem!=c.end()){
            cout<<"found,"<<*pItem<<endl;
        }
        else{
            cout<<"not found!"<<endl;
        }
    }

    {
        timeStart=clock();
        sort(c.begin(),c.end());
        string *pItem=(string*)bsearch(&target,(c.data()),c.size(),sizeof(string),compareStrings);
        cout<<"sort+bsearch,milli-seconds:"<<(clock()-timeStart)<<endl;
        if(pItem!=NULL){
            cout<<"found,"<<*pItem<<endl;
        }
        else{
            cout<<"not found!"<<endl;
        }
    }

    }

} // namespace sample02
#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <algorithm> //find()
#include <iostream>
#include <ctime> 
namespace sample03
{
    void test_list(long & value){
        cout<<"\ntest_list()\n";
        list<string>c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i =0;i<value;++i){
            try{
                snprintf(buf,10,"%d",rand());
                c.push_back(string(buf));
            }
            catch(exception &p){
                cout<<"i="<<i<<" "<<p.what()<<endl;
                abort();
            }
        }
    cout<<"milli-seconds:"<<(clock()-timeStart)<<endl;
    cout<<"list.size()="<<c.size()<<endl;
    cout<<"list.front()="<<c.front()<<endl;
    cout<<"list.back()="<<c.back()<<endl;
    cout<<"list.max_size()="<<c.max_size()<<endl;
    string target=get_a_target_string();
    timeStart=clock();
    list<string>::iterator pItem=::find(c.begin(),c.end(),target);
    cout<<"::find,micro-seconds:"<<(clock()-timeStart)<<endl;
    if (pItem!=c.end()){
        cout<<"found,"<<*pItem<<endl;
    }
    else{
        cout<<"not found!"<<endl;
    }
    timeStart=clock();
    c.sort();
    cout<<"c.sort(),micro-seconds:"<<(clock()-timeStart)<<endl;
    }
} // namespace sample03
#include<forward_list>
#include<stdexcept>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<ctime>
namespace sample04
{
    void test_forward_list(long & value){
        cout<<"\ntest_list()\n";
        forward_list<string>c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i =0;i<value;++i){
            try{
                snprintf(buf,10,"%d",rand());
                c.push_front(string(buf));
            }
            catch(exception &p){
                cout<<"i="<<i<<" "<<p.what()<<endl;
                abort();
            }
        }
    cout<<"milli-seconds:"<<(clock()-timeStart)<<endl;
    cout<<"list.front()="<<c.front()<<endl;
    cout<<"list.max_size()="<<c.max_size()<<endl;
    string target=get_a_target_string();
    timeStart=clock();
    forward_list<string>::iterator pItem=::find(c.begin(),c.end(),target);
    cout<<"::find,micro-seconds:"<<(clock()-timeStart)<<endl;
    if (pItem!=c.end()){
        cout<<"found,"<<*pItem<<endl;
    }
    else{
        cout<<"not found!"<<endl;
    }
    timeStart=clock();
    c.sort();
    cout<<"c.sort(),micro-seconds:"<<(clock()-timeStart)<<endl;
    }
} // namespace sample03

#include<deque>
#include<stdexcept>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<ctime>
namespace sample05
{
    void test_deque(long & value){
        cout<<"\test_deque()\n";
        deque<string>c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i =0;i<value;++i){
            try{
                snprintf(buf,10,"%d",rand());
                c.push_back(string(buf));
            }
            catch(exception &p){
                cout<<"i="<<i<<" "<<p.what()<<endl;
                abort();
            }
        }
    cout<<"milli-seconds:"<<(clock()-timeStart)<<endl;
    cout<<"deque.size()="<<c.size()<<endl;
    cout<<"deque.front()="<<c.front()<<endl;
    cout<<"deque.back()="<<c.back()<<endl;
    cout<<"deque.max_size()="<<c.max_size()<<endl;
    string target=get_a_target_string();
    timeStart=clock();
    auto pItem=::find(c.begin(),c.end(),target);
    cout<<"::find,micro-seconds:"<<(clock()-timeStart)<<endl;
    if (pItem!=c.end()){
        cout<<"found,"<<*pItem<<endl;
    }
    else{
        cout<<"not found!"<<endl;
    }
    timeStart=clock();
    ::sort(c.begin(),c.end());
    cout<<"c.sort(),micro-seconds:"<<(clock()-timeStart)<<endl;
    }
}

#include<set>
#include<stdexcept>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<ctime>
namespace sample06
{
    void test_multiset(long & value){
        cout<<"\ntest_multiset()\n";
        multiset<string>c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i =0;i<value;++i){
            try{
                snprintf(buf,10,"%d",rand()%10000);
                c.insert(string(buf));
            }
            catch(exception &p){
                cout<<"i="<<i<<" "<<p.what()<<endl;
                abort();
            }
        }
    cout<<"milli-seconds:"<<(clock()-timeStart)<<endl;
    cout<<"deque.size()="<<c.size()<<endl;
    cout<<"deque.max_size()="<<c.max_size()<<endl;
    string target=get_a_target_string();
    {
        timeStart=clock();
    auto pItem=::find(c.begin(),c.end(),target);
    cout<<"::find,micro-seconds:"<<(clock()-timeStart)<<endl;
    if (pItem!=c.end()){
        cout<<"found,"<<*pItem<<endl;
    }
    else{
        cout<<"not found!"<<endl;
    } 
    }

    {
    timeStart=clock();
   auto pItem=c.find(target);
     cout<<"::find,micro-seconds:"<<(clock()-timeStart)<<endl;
    if (pItem!=c.end()){
        cout<<"found,"<<*pItem<<endl;
    }
    else{
        cout<<"not found!"<<endl;
    }
    }
    }
}

#include<map>
#include<stdexcept>
#include<cstdlib>//ablort
#include<cstdio>//snprintf
#include<string>
#include<algorithm>
#include<ctime>
#include<iostream>
namespace sample07{
    void test_multimap(long & value){
        cout<<"\ntest_multimap\n";
        multimap<long,string> c;
        char buf[10];
        clock_t timeStart=clock();
        for(long i=0 ;i<value;++i){
            try{
                snprintf(buf,10,"%d",rand());
                c.insert(pair<long,string>(i,buf));
            }
           catch (exception & e){
               cout<<"i="<<i<<" "<<e.what()<<endl;
               abort();
           }
        }
        cout<<"micro-seconds:"<<(clock()-timeStart)<<endl;
        cout<<"multimap.size()"<<c.size()<<endl;
        cout<<"multimap.max_size()"<<c.max_size()<<endl;

        long target=get_a_target_long();
        timeStart=clock();
        auto pItem=c.find(target);
        cout<<"c.find(),mirco-seconds:"<<(clock()-timeStart)<<endl;
        if (pItem!=c.end())
        {
            cout<<"found,value="<<(*pItem).second<<endl;
        }
        else
            cout<<"not found!"<<endl;

    }
}

#include<unordered_set>
#include<stdexcept>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<algorithm>
#include<ctime>
#include<iostream>
namespace sample08{
    void test_unordered_multiset(long & value){
        cout<<"\ntest_unordered_multiset\n";
        unordered_multiset<string> c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i =0 ;i<value;++i){
            try{
                snprintf(buf,10,"%d",rand()%1000000);
                c.insert(string(buf));
            }
            catch (exception & p){
                cout<<"i="<<i<<" "<<p.what()<<endl;
                abort();
            }
        }
        cout<<"micro-seconds:"<<(clock()-timeStart)<<endl;
        cout<<"unordered_multiset.size()="<<c.size()<<endl;
        cout<<"unordered_multiset.max_size()="<<c.max_size()<<endl;
        cout<<"unordered_multiset.bucket_count()"<<c.bucket_count()<<endl;
        cout<<"unordered_multiset.load_factor()"<<c.load_factor()<<endl;
        cout<<"unordered_multiset.max_load_factor()"<<c.max_load_factor()<<endl;
        cout<<"unordered_multiset.max_bucket_count()"<<c.max_bucket_count()<<endl;
    for (unsigned i=0;i<20;++i){
        cout<<"bucket #"<<i<<" has "<<c.bucket_size(i)<<" elements\n";
    }
    string target =get_a_target_string();
    {
        timeStart=clock();
        auto pItem=::find(c.begin(),c.end(),target);
        cout<<"::find(),micro-seconds:"<<(clock()-timeStart)<<endl;
        if(pItem!=c.end()){
            cout<<"found,"<<(*pItem)<<endl;
        }
        else{
            cout<<"not found!"<<endl;
        }
    }
    {
        timeStart=clock();
        auto pItem=c.find(target);
         cout<<"c.find,micro-seconds:"<<(clock()-timeStart)<<endl;
        if(pItem!=c.end()){
            cout<<"found,"<<(*pItem)<<endl;
        }
        else{
            cout<<"not found!"<<endl;
        }
    }
    }
}

#include<unordered_map>
#include<stdexcept>//exception
#include<cstdio>//snprintf
#include<ctime>//clock()
#include<cstdlib>//abort rand()
#include<string>
#include<iostream>
#include<algorithm>
namespace sample09{
    void test_unordered_multimap(long & value){
        unordered_multimap<long,string>c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i =0;i<value;++i){
            snprintf(buf,10,"%d",rand()%1000000);
            c.insert(pair<long,string>(i,string(buf)));
        }
        cout<<"micro-seconds:"<<(clock()-timeStart)<<endl;
        cout<<"unordered_multimap.size()"<<c.size()<<endl;
        cout<<"unordered_multimap.max_size()"<<c.max_size()<<endl;

        long target=get_a_target_long();
        timeStart=clock();
        auto pItem=c.find(target);
        cout<<"c.find(),micro-seconds:"<<(clock()-timeStart)<<endl;
        if(pItem!=c.end()){
            cout<<"found,"<<(*pItem).second<<endl;
        }
        else{
            cout<<"not found!"<<endl;
        }
    }
}
#include<ext/slist>
#include<stdexcept>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<ctime>
namespace sample10
{
     void test_slist(long & value){
        cout<<"\ntest_list()\n";
        __gnu_cxx::slist<string>c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i =0;i<value;++i){
            try{
                snprintf(buf,10,"%d",rand());
                c.push_front(string(buf));
            }
            catch(exception &p){
                cout<<"i="<<i<<" "<<p.what()<<endl;
                abort();
            }
        }
    cout<<"milli-seconds:"<<(clock()-timeStart)<<endl;
    }
} // namespace sample10
#include<set>
#include<cstdio>//snprintf
#include<cstdlib>//abort rand
#include<stdexcept>
#include<ctime>
#include<string>
#include<iostream>
#include<algorithm>
namespace sample13{
    void test_set(long & value){
        cout<<"\ntest_set\n";
        set<string> c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i=0;i<value;++i){
            try{
                snprintf(buf,10,"%d",rand()%50000);
                c.insert(string(buf));
            }
            catch(exception & p){
                cout<<"i="<<i<<" "<<p.what()<<endl;
                abort();
            }
           
        }
        cout<<"micor-seconds:"<<(clock()-timeStart)<<endl;
        cout<<"set.size()="<<c.size()<<endl;
        cout<<"set.max_size()"<<c.max_size()<<endl;
        string target =get_a_target_string();
        {
        timeStart=clock();
        auto pItem=::find(c.begin(),c.end(),target);
        cout<<"::find(),"<<(clock()-timeStart)<<endl;
        if(pItem!=c.end()){
            cout<<"found,"<<(*pItem)<<endl;
        }
        else{
            cout<<"not found!"<<endl;
        }}
         {
            //  string target =get_a_target_string();
        timeStart=clock();
        auto pItem=c.find(target);
        cout<<"c.find(),"<<(clock()-timeStart)<<endl;
        if(pItem!=c.end()){
            cout<<"found,"<<(*pItem)<<endl;
        }
        else{
            cout<<"not found!"<<endl;
        }}
    }
}

#include<map>
#include<cstdlib>//abort rand
#include<cstdio>//snprintf
#include<stdexcept>
#include<string>
#include<iostream>
#include<ctime>
#include<algorithm>
namespace sample14{
    void test_map(long & value){
        cout<<"\ntest_map\n";
        map<long,string>c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i=0;i<value;++i){
            snprintf(buf,10,"%d",rand()%10000);
            c[i]=string(buf);
        }
        cout<<"micro-seconds:"<<(clock()-timeStart)<<endl;
        cout<<"map.size()="<<c.size()<<endl;
        cout<<"map.max_size()="<<c.max_size()<<endl;
        long target =get_a_target_long();
        timeStart=clock();
        auto pItem=c.find(target);
        if(pItem!=c.end()){
            cout<<"found,"<<(*pItem).second<<endl;
        }
        else cout<<"not found"<<endl;
        
    }
}

#include<unordered_set>
#include<cstdlib>//abort rand
#include<cstdio>//snprintf
#include<stdexcept>
#include<string>
#include<iostream>
#include<ctime>
#include<algorithm>
namespace sample15{
    void test_unordered_set(long &value){
        cout<<"\ntest_unordered_set\n";
        unordered_set<string> c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i =0;i<value;++i){
           try
           { 
               snprintf(buf,10,"%d",rand()%10000);
            c.insert(string(buf));
            }
           catch(const std::exception& e)
           {
               cout<<"i="<<i<<" "<< e.what() << '\n';
           }
        }
        cout<<"micro-seconds:"<<(clock()-timeStart)<<endl;
        cout<<"unordered_set.size()"<<c.size()<<endl;
        cout<<"unordered_set.max_size()="<<c.max_size()<<endl;
        cout<<"unordered_set.bucket_count()="<<c.bucket_count()<<endl;
        cout<<"unordered_set.max_bucket_count()="<<c.max_bucket_count()<<endl;
        cout<<"unordered_set.load_factor()="<<c.load_factor()<<endl;
        cout<<"unordered_set.max_load_factor()"<<c.max_load_factor()<<endl;
        for (unsigned i=0;i<20;++i){
            cout<<"the #"<<i<<" bucket_size():"<<c.bucket_size(i)<<endl;
        }
    }
}

#include<unordered_map>
#include<cstdlib>//abort rand
#include<cstdio>//snprintf
#include<stdexcept>
#include<string>
#include<ctime>
#include<iostream>
#include<algorithm>
namespace sample16{
    void test_unordered_map(long &value){
        cout<<"\ntest_unordered_map\n";
        unordered_map<long,string>c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i=0;i<value;++i){
            try
            {
                snprintf(buf,10,"%d",rand()%10000);
                c[i]=string(buf);
            }
            catch(const std::exception& e)
            {
                std::cout<<"i="<<i<<" " << e.what() << '\n';
            }
            
        }
        cout<<"micro-seconds:"<<(clock()-timeStart)<<endl;
        cout<<"unordered_map.size()="<<c.size()<<endl;
        cout<<"unordered_map.max_size()"<<c.max_size()<<endl;
        long target=get_a_target_long();
        // {
        //     timeStart=clock();
        //     auto pItem=::find(c.begin(),c.end(),target);
        //     cout<<"::find(),micro-seconds:"<<(clock()-timeStart);
        //     if(pItem!=c.end()){
        //         cout<<"found,"<<(*pItem).second<<endl;
        //     }
        //     else{
        //         cout<<"not found"<<endl;
        //     }
        // }
         {
            timeStart=clock();
            auto pItem=c.find(target);
            cout<<"c.find(),micro-seconds:"<<(clock()-timeStart);
            if(pItem!=c.end()){
                cout<<"found,"<<(*pItem).second<<endl;
            }
            else{
                cout<<"not found"<<endl;
            }
        }
    }
}
#include<stack>
#include<stdexcept>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<ctime>
namespace sample17
{
     void test_stack(long & value){
        cout<<"\ntest_stack()\n";
        stack<string>c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i =0;i<value;++i){
            try{
                snprintf(buf,10,"%d",rand());
                c.push(string(buf));
            }
            catch(exception &p){
                cout<<"i="<<i<<" "<<p.what()<<endl;
                abort();
            }
        }
    cout<<"milli-seconds:"<<(clock()-timeStart)<<endl;
    cout<<"deque.size()="<<c.size()<<endl;
    cout<<"deque.top()="<<c.top()<<endl;
    c.pop();
    cout<<"deque.size()="<<c.size()<<endl;
    cout<<"deque.top()="<<c.top()<<endl;
     }
} // namespace sample17
#include<queue>
#include<stdexcept>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<ctime>
namespace sample18
{
     void test_queue(long & value){
        cout<<"\ntest_queue()\n";
        queue<string>c;
        char buf[10];
        clock_t timeStart=clock();
        for (long i =0;i<value;++i){
            try{
                snprintf(buf,10,"%d",rand());
                c.push(string(buf));
            }
            catch(exception &p){
                cout<<"i="<<i<<" "<<p.what()<<endl;
                abort();
            }
        }
    cout<<"milli-seconds:"<<(clock()-timeStart)<<endl;
    cout<<"deque.size()="<<c.size()<<endl;
    cout<<"deque.front()="<<c.front()<<endl;
    cout<<"deque.back()="<<c.back()<<endl;
    c.pop();
    cout<<"deque.size()="<<c.size()<<endl;
    cout<<"deque.front()="<<c.front()<<endl;
    cout<<"deque.back()="<<c.back()<<endl;
     }
} // namespace sample18


#include<list>
#include<stdexcept>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<ctime>
#include <algorithm>

#include<cstddef>
#include<memory>//std::allocator

#include<ext/array_allocator.h>
#include<ext/mt_allocator.h>
#include<ext/debug_allocator.h>
#include<ext/pool_allocator.h>
#include<ext/bitmap_allocator.h>
#include<ext/malloc_allocator.h>
#include<ext/new_allocator.h>
namespace sample20{
    void test_list_with_special_allocator()
    {
        cout<<"\ntest_list_with_special_allocator\n";
        list<string,allocator<string>> c1;
        list<string,__gnu_cxx::array_allocator<string>> c2;
        list<string,__gnu_cxx::new_allocator<string>> c3;
        list<string,__gnu_cxx::__pool_alloc<string>> c4;
        list<string,__gnu_cxx::__mt_alloc<string>> c5;
        list<string,__gnu_cxx::bitmap_allocator<string>> c6;
        list<string,__gnu_cxx::debug_allocator<string>> c7;
        list<string,__gnu_cxx::malloc_allocator<string>> c8;
       int choice;
       long value;
      cout << "select: "
		 << " (1) std::allocator "
	     << " (2) malloc_allocator "
	     << " (3) new_allocator "
	     << " (4) __pool_alloc "
	     << " (5) __mt_alloc "
		 << " (6) bitmap_allocator ";
	
	cin >> choice;
	if ( choice != 0 ) {
		cout << "how many elements: ";
		cin >> value; 		
	}
			
char buf[10];			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", i);
	        switch (choice) 
	        {
	 	        case 1 : 	c1.push_back(string(buf)); 	
		 					break;
		        case 2 : 	c2.push_back(string(buf)); 	
		 					break;		
		        case 3 : 	c3.push_back(string(buf)); 
		 					break;		
		        case 4 : 	c4.push_back(string(buf)); 	
		 					break;		
		        case 5 : 	c5.push_back(string(buf)); 		
		 					break;		
		        case 6 : 	c6.push_back(string(buf)); 	
		 					break;				
		        default: 
		 			break;		
	        }    		   		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "a lot of push_back(), micro-seconds : " << (clock()-timeStart) << endl;	
	

    int *p;
    allocator<int> alloc1;
    p=alloc1.allocate(1);
    alloc1.deallocate(p,1);
    }
}
namespace samplexx
{
    void testConatiners(){
        int choice;
        long value;
        srand(time(NULL));

	cout << "\n\ntest_containers()......... \n";
	cout << "select: \n";
	cout << "       (1)array (2)vector (3)list (4)forward_list (5)deque (6)multiset \n";
	cout << "       (7)multimap (8)unordered_multiset (9)unordered_multimap (10)slist \n";
	cout << "       (11)hash_multiset (12)hash_multimap (13)set (14)map (15)unordered_set \n";
	cout << "       (16)unordered_map (17)stack (18)queue \n";	
	cout << " (2),(3),(5),(6),(8) will test also moveable elements. \n"; 
	cin >> choice;
	if ( choice != 1 ) { 	//1 ==> array, use ASIZE
		cout << "how many elements: ";
		cin >> value; 		
	}
        switch (choice)
        {
        case 1:
            sample01::test_array();
            break;
        case 2:
            sample02::test_vector(value);
            break;
        case 3:
            sample03::test_list(value);
            break;
        case 4:
            sample04::test_forward_list(value);
            break;
        case 5:
            sample05::test_deque(value);
            break;
        case 6:
            sample06::test_multiset(value);
            break;
        case 7:
            sample07::test_multimap(value);
            break;
        case 8:
            sample08::test_unordered_multiset(value);
            break;
        case 9:
            sample09::test_unordered_multimap(value);
            break;
        case 10:
            sample10::test_slist(value);
            break;
        case 13:
            sample13::test_set(value);
            break;
        case 14:
            sample14::test_map(value);
            break;
        case 15:
            sample15::test_unordered_set(value);
            break;
        case 16:
            sample16::test_unordered_map(value);
            break;
        case 17:
            sample17::test_stack(value);
            break;
        case 18:
            sample18::test_queue(value);
            break;
        default:
            break;
        }
    }
} // namespace samplexx


int main(){
    samplexx::testConatiners();
}