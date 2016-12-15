 ///
 /// @file    WordSegmentation.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-29 04:58:49
 ///
 
#ifndef __WORDSEGMENTATION_H__
#define __WORDSEGMENTATION_H__

#include "cppjieba/include/cppjieba/Jieba.hpp"
#include "cppjieba/deps/limonp/Colors.hpp"
#include "cppjieba/deps/limonp/Logging.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

using namespace cppjieba;
namespace zx
{

	const char* const DICT_PATH = "cppjieba/dict/jieba.dict.utf8";
	const char* const HMM_PATH = "cppjieba/dict/hmm_model.utf8";
	const char* const USER_DICT_PATH = "cppjieba/dict/user.dict.utf8";
	const char* const IDF_PATH = "cppjieba/dict/idf.utf8";
	const char* const STOP_WORD_PATH = "cppjieba/dict/stop_words.utf8";

	class WordSegmentation
	{
		public:
			WordSegmentation()
			:_jieba(DICT_PATH,HMM_PATH,USER_DICT_PATH,IDF_PATH,STOP_WORD_PATH)
			{

			}
			vector<string> cut(const string & sentence)
			{
				_jieba.Cut(sentence,_words, true);
				return _words;
			}
			vector<string> topWords(const string & sentence)
			{
				vector<string> top;
				_jieba.extractor.Extract(sentence,top,20);
				return top;
			}
	//		WordSegmentation(const string & sentence);
	//		vector<string>getWords();
		private:
			vector<string> _words;
		//	string _sentence;
			Jieba _jieba;
	};

}//end of namespace zx



#endif
