#include "Funk.h"

int main()
{
    //9.4
    vector <int> search = { 1,2,3,4,5,6,7,8,9 };
    vector <int>::iterator a, b;
    int searchible = 6;
    a = search.begin();
    b = search.begin() + 5;
    cout << "9.4: From [0 to 5] position at vector 1-9 number = " << searchible << "  Was found? - " 
        << iter_search(a, b, searchible) << endl;

    //9.5
    searchible = -1;
    cout << "9.5: From [0 to 5] position at vector 1-9 number = " << searchible;
    vector <int>::iterator result;
    result = iter_search_back(a, b, searchible);
    if (result == vector <int>::iterator())
        cout << ". The element not found" << endl;
    else
        cout << ". We find the element: " << *result << endl;

    //9.14
    list <const char*> words; // { "Crown", "Letter", "Promise", "Crossroad" };
    vector <string> str_words;
    words.push_back("Crown");
    words.push_back("Letter");
    words.push_back("Promise");
    words.push_back("Crossroad");

    char_to_str(words, str_words);

    cout << "9.14: List of char*: ";
    print_list(words);
    cout << "become a vector of string: ";
    print_vec(str_words);

    //9.15
    vector <int> second = { 1,2,3,4,5,6,7,8,8 };
    cout << "9.15: Vector 1: ";
    print_vec(search);
    cout << "And vector 2: ";
    print_vec(second);
    cout << (vec_equal(search, second) ? "Are equal" : "Are not equal") << endl;

    //9.16
    list <int> third = { 1,2,3,4,5,6,7,8,9 };
    cout << "9.16: Vector 1: ";
    print_vec(search);
    cout << "And vector 2: ";
    print_vec(second);
    cout << (vec_list_equal(third, search) ? "Are equal" : "Are not equal") << endl;

    //9.18
    vector <string> tmp;
    string curr;
    cout << "9.18: Enter strings (\"end\" to stop): \n";
    while (curr != "end")
    {
        tmp.push_back(curr);
        getline(cin, curr);

    }
    deque <string> deq (tmp.size());
    deq_fill(tmp, deq);
    cout << "Now, you have a string at deque: \n";
    print_deq_str(deq);

    //9.19
    list <string> d_list (tmp.size());
    list_fill(tmp, d_list);
    cout << "9.19: Now, you have a string at list: \n";
    print_list(d_list);

    //9.20
    //list <int> third;
    deque <int> deq1;
    deque <int> deq2;
    cout << "9.20: Our list: " << endl;
    print_list(third);
    list_from_deqs(third, deq1, deq2);
    cout << "Sepatate for two deques, \nFirst:";
    print_deq_int(deq1);
    cout << "Second: \n";
    print_deq_int(deq2);

    //9.24
    //vector <int> second;
    vector <int> s0;
    vec_at(second);
    try
    {
        vec_at(s0);
    }
    catch (exception)
    {
        cout << "Can'not take a 0 elem of empty vector";
    }

    //9.26
    int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 }; //Why there are no Fibbanachi line at the book?
    vector <int> sep_v;
    list <int> sep_l;
    sep_v.assign(ia, ia + 11);
    sep_l.assign(ia, ia + 11);
    mass_sep(sep_v, sep_l);
    cout << "9.26: Out line: { 0,1,1,2,3,5,8,13,21,55,89 } Separates for: \n Vector: ";
    print_vec(sep_v);
    cout << "List: ";
    print_list(sep_l);

    //9.27
    forward_list <int> fw_l = { 1, 2, 3, 4, 5 };
    cout << "9.27: Out forward list: ";
    print_fwl_int(fw_l);
    forward_list_del(fw_l);
    cout << "Erased forward list: ";
    print_fwl_int(fw_l);

    //9.28
    forward_list <string> fw_str;
    fw_str.push_front("Crown");
    fw_str.push_front("Letter");
    fw_str.push_front("Promise");
    fw_str.push_front("Crossroad"); 
    cout << "9.28: Out forward list of strings: ";
    print_fwl_str(fw_str);
    forward_list_search(fw_str, "Crown", "Smile");
    cout << "Edit forward list of strings: ";
    print_fwl_str(fw_str);

    //9.41
    vector <char> vec_char = {'a','b','r','a','k','o','b','r','a'};
    cout << "9.41: Out vector of char: {'a','b','r','a','k','o','b','r','a'} \n";
    cout << "And result of string: " << v_char_str(vec_char) << endl;

    //9.43
    string s = "thotho";
    string old_val = "tho";
    string new_val = "though";
    cout << "9.43: Original string:  " << s << "  Edited string:  " << edit_str(s, old_val, new_val) << endl;

    //9.44
    s = "thruthru";
    old_val = "thru";
    new_val = "through";
    cout << "9.44: Original string:  " << s << "  Edited string:  " << edit_str_replace(s, old_val, new_val) << endl;


    //10.11
    // vector <string> tmp (you should enter it)
    cout << "10.11: Original vector :\n";
    print_vec(tmp);
    elimdups(tmp);
    cout << "Elimdups vector :\n";
    print_vec(tmp);
    stable_sort(tmp.begin(), tmp.end(), isShorter);
    cout << "Stable sort vector :\n";
    print_vec(tmp);

    //10.12
    vector <Sales> st;
    st.push_back(Sales(4));
    st.push_back(Sales(15));
    st.push_back(Sales(-2));
    st.push_back(Sales(8));

    cout << "10.12: Original vector :\n";
    print_vec(st);
    sort(st.begin(), st.end(), compare_class);
    cout << "Sorted vector :\n";
    print_vec(st);

    //10.14
    cout << "110.14: Original vector :\n";
    print_vec(search);
    //for_each(second.begin(), second.end(), [](int& curr) {return  curr += val1; });

    //10.15
    int val1 = 3, val2 = 5;
    cout << "10.15: Original vector :\n";
    print_vec(second);
    for_each (second.begin(), second.end(), [val1](int& curr) {return  curr += val1;});
    cout << "Sorted vector :\n";
    print_vec(second);

    //10.17
    cout << "10.17: Original vector :\n";
    print_vec(st);
    sort(st.begin(), st.end(), [](Sales& a, Sales& b) {return a.id > b.id; });
    cout << "Sorted vector :\n";
    print_vec(st);

    //10.27
    vector <string> with_copy;
    with_copy.push_back("Hi");
    with_copy.push_back("Aoa");
    with_copy.push_back("Hi");
    with_copy.push_back("Fello");
    cout << "10.27: Original vector :\n";
    print_vec(with_copy);
    cout << "Sorted vector whith no copies:\n";
    print_vec(unique_dupp(with_copy));

    //10.28
    //vector <int> search
    vector <int> bi, in;
    list <int> fi;
    print_vec(search);
    unique_copy(search.begin(), search.end(), back_inserter(bi));
    unique_copy(search.begin(), search.end(), front_inserter(fi));
    unique_copy(search.begin(), search.end(), inserter(in, in.begin()));
    cout << "10.28: Original vector :\n";
    print_vec(search);
    cout << "Back_inserted vector :\n";
    print_vec(bi);
    cout << "Front_inserted vector :\n";
    print_list(fi);
    cout << "Inserted vector :\n";
    print_vec(in);

    //10.29
    vector <int> biz;
    cout << "10.29: Enter some numbers (-1 to end) :\n";
    istream_iterator<int> init(cin);
    while (*init != -1)
    {
        biz.push_back(*init++);
    }
    print_vec(biz);

    //10.30
    vector <int> bizz;
    cout << "10.30: Enter some numbers (-1 to end) :\n";
    istream_iterator<int> initl(cin);
    ostream_iterator<int> onitl(cout, " ");

    while (*initl != -1)
    {
        bizz.push_back(*initl++);
    }
    cout << " Original vector :\n";
    print_vec(bizz);
    cout << " Sorted vector :\n";
    sort(bizz.begin(), bizz.end());
    copy(bizz.begin(), bizz.end(), onitl);

    //10.31
    vector <int> bizzly;
    list <int> bizzy;
    cout << "\n10.31: Enter some numbers (-1 to end) :\n";
    istream_iterator<int> initf(cin);
    //ostream_iterator<int> onitl(cout, "");

    while (*initf != -1)
    {
        bizzly.push_back(*initf++);
    }
    cout << " Original vector :\n";
    print_vec(bizz);
    cout << " Unique vector :\n";
    unique_copy(bizzly.begin(), bizzly.end(), front_inserter(bizzy));
    copy(bizzy.begin(), bizzy.end(), onitl);

}


