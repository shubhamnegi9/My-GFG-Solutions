// User function Template for C++

void toBinary(int n) {
    string s = "";
    while(n) {
        if(n%2 == 0)
            s += '0';
        else
            s += '1';
        n/=2;
    }
    reverse(s.begin(), s.end());
    cout << s;
}