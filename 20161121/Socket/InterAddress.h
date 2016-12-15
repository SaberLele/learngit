 ///
 /// @file    InterAddress.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-20 17:50:57
 ///

#ifndef __INTERADDRESS_H__
#define __INTERADDRESS_H__

#include <string>
#include <netinet/in.h>

namespace zx
{

	class InetAddress
	{
		public:
			explicit InetAddress(uint16_t port);
			InetAddress(const std::string &ip, uint16_t port);
			InetAddress(const struct sockaddr_in &addr);

			void setSockAddrInet(const struct sockaddr_in &addr)
			{ addr_=addr; }
			const struct sockaddr_in* getSockAddrInet() const
			{ return &addr_; }

			std::string toIp() const;
			uint16_t toPort() const;

		private:
			struct sockaddr_in addr_;
	};

}//end of namespace zx

#endif
