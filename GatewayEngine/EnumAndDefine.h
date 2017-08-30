#pragma once

#ifndef RETURN_SUCCEED
#define RETURN_SUCCEED	0		///成功
#endif // 

#ifndef ERROR_INVALID_PARAM
#define ERROR_INVALID_PARAM -1000 //非法参数
#endif

#ifndef ERROR_BIND_FAIL
#define ERROR_BIND_FAIL -2012 //绑定失败
#endif

#ifndef ERROR_LISTEN_FAIL
#define ERROR_LISTEN_FAIL -2013 //监听失败
#endif

#ifndef ERROR_ACCEPT_FAIL
#define ERROR_ACCEPT_FAIL -2014 //接收信息失败
#endif

#ifndef ERROR_SEND_FAIL
#define ERROR_SEND_FAIL -2015 //发送信息失败
#endif