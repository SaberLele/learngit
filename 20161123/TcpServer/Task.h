 ///
 /// @file    Task.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 00:55:07
 ///

#ifndef __TASK_H__
#define __TASK_H__

#include <functional>
using std::function;

namespace zx
{
#if 0		
	class Task
	{
		typedef function<void()> TaskCallback;
		public:
			Task(TaskCallback tc)
			:_tc(tc)
			{}
			void getTask()
			{
				_tc();	
			}
			//virtual void execute()=0;
		private:
			TaskCallback _tc;
	};
#endif

	typedef function<void()> Task;

}//end of namespace zx

#endif
