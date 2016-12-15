 ///
 /// @file    test.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-28 05:49:37
 ///

#include "cppjieba/include/cppjieba/Jieba.hpp"
#include "cppjieba/deps/limonp/Colors.hpp"
#include "cppjieba/deps/limonp/Logging.hpp"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::vector;
using std::endl;
using std::string;

const char* const DICT_PATH = "cppjieba/dict/jieba.dict.utf8";
const char* const HMM_PATH = "cppjieba/dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "cppjieba/dict/user.dict.utf8";
const char* const IDF_PATH = "cppjieba/dict/idf.utf8";
const char* const STOP_WORD_PATH = "cppjieba/dict/stop_words.utf8";

int main()
{
	cppjieba::Jieba jieba(DICT_PATH,
			HMM_PATH,
			USER_DICT_PATH,
			IDF_PATH,
			STOP_WORD_PATH);	
	vector<string> words;
	string s;
	s = "他来到了网易杭研大厦,小明硕士毕业于中国科学院计算所，后在日本京都大学深造";

	cout << s << endl;
	jieba.Cut(s, words, true);
	
#if 0
	vector<string>::iterator iter = words.begin();
	for(;iter!=words.end();++iter)
	{
		cout << *iter << endl;
	}
#endif
	cout << limonp::Join(words.begin(), words.end(), "/") << endl;

	jieba.CutAll(s, words);
	cout << limonp::Join(words.begin(), words.end(), "/") << endl;

	jieba.CutForSearch(s, words);
	cout << limonp::Join(words.begin(), words.end(), "/") << endl;

}
