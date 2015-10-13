#include <iostream>
#include <chrono>
#include "Key.h"
#include <map>
#include <vector>
#include <utility>

using namespace std;
using KeyMap = map<Key, vector<Key>>;

int
main(int argc, char* argv[])
{
  unsigned char buffer[C+1];     // temporary string buffer
  Key encrypted;                 // the encrypted password
  Key zero = {{0}};              // the all zero key
  Key T[N];                      // the table T


  if (argc != 2)
    {
      cout << "Usage:" << endl << argv[0] << " password < rand8.txt" << endl;

      return 1;
    }

  encrypted = KEYinit((unsigned char *) argv[1]);

  // read in table T
  for (int i{0}; i < N; ++i)
    {
      scanf("%s", buffer);
      T[i] = KEYinit(buffer);
    }

  auto begin = chrono::high_resolution_clock::now();

  Key half_iterator{{0}};
  half_iterator++;
  for (int i = 0; i <= N/2; ++i) {
    half_iterator = half_iterator + half_iterator;
  }

  KeyMap encrypted_table;

  Key lower_half{{0}};
  do {
    encrypted_table[encrypted - KEYsubsetsum(lower_half, T)].push_back(lower_half);
    ++lower_half;
  } while(lower_half <= half_iterator);

  Key higher_half{{0}};
  do {
    KeyMap::iterator iterator = encrypted_table.find(KEYsubsetsum(higher_half, T));
    if (iterator != encrypted_table.end()) {
      for (Key candidate : iterator->second) {
        cout << higher_half + candidate << endl;
      }
    }
    higher_half = higher_half + half_iterator;
  } while (higher_half != zero);


  auto end = chrono::high_resolution_clock::now();
  cout << "Decryption took "
       << std::chrono::duration_cast<chrono::seconds>(end - begin).count()
       << " seconds." << endl;

  return 0;
}
