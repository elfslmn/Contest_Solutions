"Random Generators"
Both of them is in <random> header

"1- rand()"
/* rand() -> pseudo random between 0 and 32767 ( not uniform)
   srand() -> give a seed
   srand( time(NULL) )
   randomshuffle() also uses and() */
   
   
"2- mt19937  Better and much faster rand
int main() {
    // obtain a seed from the system clock:
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    mt19937 generator (seed);  // mt19937 is a standard mersenne_twister_engine
    cout << "Random value: " << generator() << endl;
    
    vector<int> permutation(N);
    for (int i = 0; i < N; i++)
        permutation[i] = i;

    shuffle(permutation.begin(), permutation.end(), generator);

    for (int i = 0; i < N; i++)
        permutation[i] = i;

    for (int i = 1; i < N; i++)
        swap(permutation[i], permutation[uniform_int_distribution<int>(0, i)(generator)]);

}   
