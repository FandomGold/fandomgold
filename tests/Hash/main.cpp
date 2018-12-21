// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#include <cstddef>
#include <fstream>
#include <iomanip>
#include <ios>
#include <string>
#include <cfenv>

#include "crypto/hash.h"
#include "crypto/variant2_int_sqrt.h"
#include "../Io.h"

using namespace std;
typedef Crypto::Hash chash;

Crypto::cn_context *context;

extern "C" {
#ifdef _MSC_VER
#pragma warning(disable: 4297)
#endif

  static void hash_tree(const void *data, size_t length, char *hash) {
    if ((length & 31) != 0) {
      throw ios_base::failure("Invalid input length for tree_hash");
    }
    Crypto::tree_hash((const char (*)[32]) data, length >> 5, hash);
  }

  static void slow_hash(const void *data, size_t length, char *hash) {
    cn_slow_hash(*context, data, length, *reinterpret_cast<chash *>(hash));
  }
  static void cn_slow_hash_1(const void *data, size_t length, char *hash) { 
     return cn_slow_hash(data, length, hash, 1/*variant*/, 0/*prehashed*/);
  }
  static void cn_slow_hash_2(const void *data, size_t length, char *hash) {
     return cn_slow_hash(data, length, hash, 2/*variant*/, 0/*prehashed*/);
  }
}

extern "C" typedef void hash_f(const void *, size_t, char *);
struct hash_func {
  const string name;
  hash_f &f;
} hashes[] = {{"fast", Crypto::cn_fast_hash}, {"slow", slow_hash}, {"tree", hash_tree},
  {"extra-blake", Crypto::hash_extra_blake}, {"extra-groestl", Crypto::hash_extra_groestl},
  {"extra-jh", Crypto::hash_extra_jh}, {"extra-skein", Crypto::hash_extra_skein}};
  {"slow-1", cn_slow_hash_1}, {"slow-2", cn_slow_hash_2}};

 int test_variant2_int_sqrt();
 int test_variant2_int_sqrt_ref();

int main(int argc, char *argv[]) {
  hash_f *f;
  hash_func *hf;
  fstream input;
  vector<char> data;
  chash expected, actual;
  size_t test = 0;
  bool error = false;
  if (argc != 3) {
         if ((argc == 2) && (strcmp(argv[1], "variant2_int_sqrt") == 0)) {
       if (test_variant2_int_sqrt_ref() != 0) {
         return 1;
       }
       const int round_modes[3] = { FE_DOWNWARD, FE_TONEAREST, FE_UPWARD };
       for (int i = 0; i < 3; ++i) {
         std::fesetround(round_modes[i]);
         const int result = test_variant2_int_sqrt();
         if (result != 0) {
           cerr << "FPU round mode was set to ";
           switch (round_modes[i]) {
             case FE_DOWNWARD:
               cerr << "FE_DOWNWARD";
               break;
             case FE_TONEAREST:
               cerr << "FE_TONEAREST";
               break;
             case FE_UPWARD:
               cerr << "FE_UPWARD";
               break;
             default:
               cerr << "unknown";
               break;
           }
           cerr << endl;
           return result;
         }
       }
       return 0;
     }
    cerr << "Wrong number of arguments" << endl;
    return 1;
  }
  for (hf = hashes;; hf++) {
    if (hf >= &hashes[sizeof(hashes) / sizeof(hash_func)]) {
      cerr << "Unknown function" << endl;
      return 1;
    }
    if (argv[1] == hf->name) {
      f = &hf->f;
      break;
    }
  }
  if (f == slow_hash) {
    context = new Crypto::cn_context();
  }
  input.open(argv[2], ios_base::in);
  for (;;) {
    ++test;
    input.exceptions(ios_base::badbit);
    get(input, expected);
    if (input.rdstate() & ios_base::eofbit) {
      break;
    }
    input.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
    input.clear(input.rdstate());
    get(input, data);
    f(data.data(), data.size(), (char *) &actual);
    if (expected != actual) {
      size_t i;
      cerr << "Hash mismatch on test " << test << endl << "Input: ";
      if (data.size() == 0) {
        cerr << "empty";
      } else {
        for (i = 0; i < data.size(); i++) {
          cerr << setbase(16) << setw(2) << setfill('0') << int(static_cast<unsigned char>(data[i]));
        }
      }
      cerr << endl << "Expected hash: ";
      for (i = 0; i < 32; i++) {
          cerr << setbase(16) << setw(2) << setfill('0') << int(reinterpret_cast<unsigned char *>(&expected)[i]);
      }
      cerr << endl << "Actual hash: ";
      for (i = 0; i < 32; i++) {
          cerr << setbase(16) << setw(2) << setfill('0') << int(reinterpret_cast<unsigned char *>(&actual)[i]);
      }
      cerr << endl;
      error = true;
    }
  }
  return error ? 1 : 0;
}
#if defined(__x86_64__) || (defined(_MSC_VER) && defined(_WIN64))
 
 #include <emmintrin.h>
 
 #if defined(_MSC_VER) || defined(__MINGW32__)
   #include <intrin.h>
 #else
   #include <wmmintrin.h>
 #endif
 
 #endif
 
 static inline bool test_variant2_int_sqrt_sse(const uint64_t sqrt_input, const uint64_t correct_result)
 {
 #if defined(__x86_64__) || (defined(_MSC_VER) && defined(_WIN64))
   uint64_t sqrt_result;
   VARIANT2_INTEGER_MATH_SQRT_STEP_SSE2();
   VARIANT2_INTEGER_MATH_SQRT_FIXUP(sqrt_result);
   if (sqrt_result != correct_result) {
     cerr << "Integer sqrt (SSE2 version) returned incorrect result for N = " << sqrt_input << endl;
     cerr << "Expected result: " << correct_result << endl;
     cerr << "Returned result: " << sqrt_result << endl;
     return false;
   }
 #endif
 
   return true;
 }
 
 static inline bool test_variant2_int_sqrt_fp64(const uint64_t sqrt_input, const uint64_t correct_result)
 {
 #if defined DBL_MANT_DIG && (DBL_MANT_DIG >= 50)
   uint64_t sqrt_result;
   VARIANT2_INTEGER_MATH_SQRT_STEP_FP64();
   VARIANT2_INTEGER_MATH_SQRT_FIXUP(sqrt_result);
   if (sqrt_result != correct_result) {
     cerr << "Integer sqrt (FP64 version) returned incorrect result for N = " << sqrt_input << endl;
     cerr << "Expected result: " << correct_result << endl;
     cerr << "Returned result: " << sqrt_result << endl;
     return false;
   }
 #endif
 
   return true;
 }
 
 static inline bool test_variant2_int_sqrt_ref(const uint64_t sqrt_input, const uint64_t correct_result)
 {
   uint64_t sqrt_result;
   VARIANT2_INTEGER_MATH_SQRT_STEP_REF();
   if (sqrt_result != correct_result) {
     cerr << "Integer sqrt (reference version) returned incorrect result for N = " << sqrt_input << endl;
     cerr << "Expected result: " << correct_result << endl;
     cerr << "Returned result: " << sqrt_result << endl;
     return false;
   }
 
   return true;
 }
 
 static inline bool test_variant2_int_sqrt(const uint64_t sqrt_input, const uint64_t correct_result)
 {
   if (!test_variant2_int_sqrt_sse(sqrt_input, correct_result)) {
     return false;
   }
   if (!test_variant2_int_sqrt_fp64(sqrt_input, correct_result)) {
     return false;
   }
 
   return true;
 }
 
 int test_variant2_int_sqrt()
 {
   if (!test_variant2_int_sqrt(0, 0)) {
     return 1;
   }
   if (!test_variant2_int_sqrt(1ULL << 63, 1930543745UL)) {
     return 1;
   }
   if (!test_variant2_int_sqrt(uint64_t(-1), 3558067407UL)) {
     return 1;
   }
 
   for (uint64_t i = 1; i <= 3558067407UL; ++i) {
     // "i" is integer part of "sqrt(2^64 + n) * 2 - 2^33"
     // n = (i/2 + 2^32)^2 - 2^64
 
     const uint64_t i0 = i >> 1;
     uint64_t n1;
     if ((i & 1) == 0) {
       // n = (i/2 + 2^32)^2 - 2^64
       // n = i^2/4 + 2*2^32*i/2 + 2^64 - 2^64
       // n = i^2/4 + 2^32*i
       // i is even, so i^2 is divisible by 4:
       // n = (i^2 >> 2) + (i << 32)
 
       // int_sqrt_v2(i^2/4 + 2^32*i - 1) must be equal to i - 1
       // int_sqrt_v2(i^2/4 + 2^32*i) must be equal to i
       n1 = i0 * i0 + (i << 32) - 1;
     }
     else {
       // n = (i/2 + 2^32)^2 - 2^64
       // n = i^2/4 + 2*2^32*i/2 + 2^64 - 2^64
       // n = i^2/4 + 2^32*i
       // i is odd, so i = i0*2+1 (i0 = i >> 1)
       // n = (i0*2+1)^2/4 + 2^32*i
       // n = (i0^2*4+i0*4+1)/4 + 2^32*i
       // n = i0^2+i0+1/4 + 2^32*i
       // i0^2+i0 + 2^32*i < n < i0^2+i0+1 + 2^32*i
 
       // int_sqrt_v2(i0^2+i0 + 2^32*i) must be equal to i - 1
       // int_sqrt_v2(i0^2+i0+1 + 2^32*i) must be equal to i
       n1 = i0 * i0 + i0 + (i << 32);
     }
 
     if (!test_variant2_int_sqrt(n1, i - 1)) {
       return 1;
     }
     if (!test_variant2_int_sqrt(n1 + 1, i)) {
       return 1;
     }
   }
 
   return 0;
 }
 
 int test_variant2_int_sqrt_ref()
 {
   if (!test_variant2_int_sqrt_ref(0, 0)) {
     return 1;
   }
   if (!test_variant2_int_sqrt_ref(1ULL << 63, 1930543745UL)) {
     return 1;
   }
   if (!test_variant2_int_sqrt_ref(uint64_t(-1), 3558067407UL)) {
     return 1;
   }
 
   // Reference version is slow, so we test only every 83th edge case
   // "i += 83" because 1 + 83 * 42868282 = 3558067407
   for (uint64_t i = 1; i <= 3558067407UL; i += 83) {
     const uint64_t i0 = i >> 1;
     uint64_t n1;
     if ((i & 1) == 0) {
       n1 = i0 * i0 + (i << 32) - 1;
     }
     else {
       n1 = i0 * i0 + i0 + (i << 32);
     }
 
     if (!test_variant2_int_sqrt_ref(n1, i - 1)) {
       return 1;
     }
     if (!test_variant2_int_sqrt_ref(n1 + 1, i)) {
       return 1;
     }
   }
 
   return 0;
 }
