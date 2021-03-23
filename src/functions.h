#ifndef FUNCTIONS_H
#define FUNCTIONS_H

# include <seqan/seq_io.h>
# include <seqan/sequence.h>
# include <iostream>
using namespace seqan;

void LoadBarcodeIndex(std::string & Index_name, std::vector<std::string> & BCI_barcodes, std::vector<std::pair<std::streampos,std::streampos>> & BCI_positions);
void ReturnBarcodeReads(std::vector<std::string> & BCI_barcodes, std::vector<std::pair<std::streampos,std::streampos>> & BCI_positions, std::string & barcode, const char* readfile1, const char* readfile2);
void ReportWindow(std::vector<std::tuple<double,unsigned char,uint32_t,uint32_t>> & best_windows, std::tuple<double,unsigned char,uint32_t,uint32_t> & candidate);
int64_t ReturnSmaller(const int64_t hash1,const int64_t hash2,const int64_t random_seed);
int64_t InitMini(const DnaString & string, const uint_fast8_t k, std::pair <int64_t, int64_t> & hash, const int64_t & maxhash,const int64_t random_seed, int64_t & minimizer_position);
void AppendPos(std::vector<std::tuple <unsigned char,uint32_t,uint32_t,uint32_t>> & kmer_list, const int64_t & hash, const String<int64_t> & C,const String<uint32_t> & dir,const String<std::pair <unsigned char,uint32_t>> & pos, const uint_fast32_t bucket_number, uint_fast8_t & minimizer_active_bases);
DnaString hash2kmer(const int64_t & hash,const uint_fast8_t k);
std::pair <int64_t,int64_t> hashkMer(const DnaString & kmer, const uint_fast8_t k);
void rollinghashkMer(int64_t & oldHash, int64_t & oldHash2, const Dna5 & newnuc, const uint_fast8_t k, const int64_t & maxhash);
uint_fast32_t GetBkt(const int64_t & hash, const String<int64_t> & C, const uint_fast32_t bucket_number);
uint_fast32_t ReqBkt(const int64_t & hash, String<int64_t> & C, const uint_fast32_t bucket_number);
std::vector<std::pair <unsigned char,uint32_t>> RetPos(const int64_t & hash, const String<int64_t> & C,const String<uint32_t> & dir,const String<std::pair <unsigned char,uint32_t>> & pos, const uint_fast32_t bucket_number);

#endif
