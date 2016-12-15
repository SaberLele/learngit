 ///
 /// @file    WordSegmentation.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-29 05:08:39
 ///

#include "WordSegmentation.h"
#include <boost/regex.hpp>

namespace zx
{

#if 0
	boost::regex reg1("\\s*");
	WordSegmentation::WordSegmentation(const string & sentence)
	:_sentence(regex_replace(sentence,reg1,""))
	,_jieba(DICT_PATH,HMM_PATH,USER_DICT_PATH,IDF_PATH,STOP_WORD_PATH)
	{
	}
	
	vector<string> WordSegmentation::getWords()
	{
		cppjieba::Jieba jieba(DICT_PATH,
				HMM_PATH,
				USER_DICT_PATH,
				IDF_PATH,
				STOP_WORD_PATH);
		jieba.Cut(_sentence,_words, true);
		return _words;
	}
#endif

}//end of namespace zx
