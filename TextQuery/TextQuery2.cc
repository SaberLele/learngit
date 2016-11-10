 ///
 /// @file    TextQuery.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-08 18:55:52
 ///
 
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::ifstream;
using std::ostream;

class QueryResult;
class TextQuery
{
	public:
		using line_no=vector<string>::size_type;
		TextQuery(ifstream&);
		QueryResult query(const string&) const;
	private:
		shared_ptr<vector<string> > file;
		map<string,shared_ptr<set<line_no> > > wm;
};

TextQuery::TextQuery(ifstream & is)
:file(new vector<string>)
{
	string text;
	while(getline(is,text))
	{
		file->push_back(text);
		int n=file->size()-1;    //当前行号
		std::istringstream line(text);
		string word;
		while(line >> word)
		{
			auto &lines=wm[word];
			if(!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult
{
	friend ostream & print(ostream &,const QueryResult &);
	public:
		QueryResult(string s,
					shared_ptr<set<TextQuery::line_no> > p,
					shared_ptr<vector<string> > f)
		:sought(s)
		,lines(p)
		,file(f)
		{}
		const shared_ptr<vector<string> > getfile()const
		{
			return file;
		}
	//	const shared_ptr<set<TextQuery::line_no> >getline() const
	//	{
	//		return lines;
	//	}
		set<TextQuery::line_no>::iterator begin()
		{
			set<TextQuery::line_no>::iterator it=lines->begin();
			return it;
		}
		set<TextQuery::line_no>::iterator end()
		{
			set<TextQuery::line_no>::iterator it=lines->end();
			return it;
		}

	private:
		string sought;
		shared_ptr<set<TextQuery::line_no> > lines;
		shared_ptr<vector<string> > file;
};

QueryResult TextQuery::query(const string & sought) const
{
	static shared_ptr<set<line_no> > nodata(new set<line_no>);
	auto loc=wm.find(sought);
	if(loc==wm.end())
		return QueryResult(sought,nodata,file);
	else
		return QueryResult(sought,loc->second,file);
}

string make_plural(size_t ctr,const string & word,const string & ending)
{
	return (ctr>1) ? word + ending : word;
}

ostream & print(ostream & os,const QueryResult & qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << make_plural(qr.lines->size(),"time","s") << endl;
#if 1
	for(auto num : *qr.lines)
	{
		os << "\t(line " << num+1 << ")"
		   << *(qr.file->begin()+num) << endl;
	}
	return os;
#endif
}
#if 0
void runQueries(ifstream & infile)
{
	TextQuery tq(infile);
	while(true)
	{
		cout << "enter word to look for,or q to quit" << endl;
		string s;
		if(!(std::cin>>s)||s=="q")
			break;
		print(cout ,tq.query(s)) << endl;
	}

}
#endif

class Query_base
{
	friend class Query;
	protected:
		using line_no=TextQuery::line_no;
		virtual ~Query_base()
		{}
	private:
		virtual QueryResult eval(const TextQuery&) const=0;
		virtual string rep() const =0;
};

class WordQuery
:public Query_base
{
	friend class Query;
	WordQuery(const string & s)
	:query_word(s)
	{}

	QueryResult eval(const TextQuery & t) const
	{
		return t.query(query_word);
	}
	string rep() const
	{
		return query_word;
	}
	string query_word;
};

class Query
{
	friend Query operator ~ (const Query&);
	friend Query operator | (const Query& ,const Query&);
	friend Query operator & (const Query& ,const Query&);

	public:
		Query(const string &s)
		:q(new WordQuery(s))
		{}
		QueryResult eval(const TextQuery &t) const
		{
			return q->eval(t);
		}
		string rep() const
		{
			return q->rep();
		}
	private:
		Query(shared_ptr<Query_base> query)
	:q(query)
		{
			cout << "Query(shared_ptr<Query_base>)" << endl;
		}
		shared_ptr<Query_base> q;
};

class NotQuery
:public Query_base
{
	friend Query operator ~(const Query &);
	NotQuery(const Query & q)
	:query(q)
	{}
	QueryResult eval(const TextQuery&) const;
	string rep() const
	{
		return "~(" + query.rep() + ")";
	}
	Query query;
};
inline Query operator ~ (const Query & rhs)
{
	return shared_ptr<Query_base>(new NotQuery(rhs));
}

QueryResult NotQuery::eval(const TextQuery& text) const
{
	auto result=query.eval(text);
	auto ret_lines=make_shared<set<line_no> >();
	auto beg=result.begin(), end=result.end();
	auto sz=result.getfile()->size();
	for(size_t n=0;n!=sz;++n)
	{
		if(beg==end||*beg!=n)
			ret_lines->insert(n);
		else if(beg!=end)
		{
			++beg;
		}
	}
	return QueryResult(rep(),ret_lines,result.getfile());
}

class BinaryQuery
: public Query_base
{
	protected:
		BinaryQuery(const Query & l,const Query & r,string s)
		:lhs(l)
		,rhs(r)
		,opSym(s)
		{}
		string rep() const
		{
			return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
		}

		Query lhs,rhs;
		string opSym;
};

class AndQuery
:public BinaryQuery
{
	friend Query operator & (const Query &,const Query &);
	AndQuery(const Query &left,const Query &right)
	:BinaryQuery(left,right,"&")
	{}

	QueryResult eval(const TextQuery&) const;
};
inline Query operator & (const Query &lhs,const Query &rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}
QueryResult AndQuery::eval(const TextQuery& text) const
{
	auto left=lhs.eval(text),right=rhs.eval(text);
	auto ret_lines=make_shared<set<line_no> >();
	std::set_intersection(left.begin(),left.end(),
						  right.begin(),right.end(),
						  std::inserter(*ret_lines,ret_lines->begin()));
	return QueryResult(rep(),ret_lines,left.getfile());
}

class OrQuery
:public BinaryQuery
{
	friend Query operator|(const Query &,const Query &);
	OrQuery(const Query &left,const Query &right)
	:BinaryQuery(left,right,"|")
	{}
	QueryResult eval(const TextQuery&) const;
};
inline Query operator|(const Query &lhs,const Query &rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}
QueryResult
OrQuery::eval(const TextQuery& text) const
{
	auto right=rhs.eval(text),left=lhs.eval(text);
	auto ret_lines=make_shared<set<line_no> >(left.begin(),left.end());
	ret_lines->insert(right.begin(),right.end());
	return QueryResult(rep(),ret_lines,left.getfile());
}


int main()
{
	string filename="data.txt";
	ifstream ifs(filename.c_str());
	TextQuery tq(ifs);
//	Query query=Query("fiery")|Query("Wind");
	Query query= ~ Query("Wind");
	print(cout,query.eval(tq));
	cout << endl;
}


