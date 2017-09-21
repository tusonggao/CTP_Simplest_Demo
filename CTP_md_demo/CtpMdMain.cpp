#include ".\ThostTraderApi\ThostFtdcMdApi.h"
#include "MdSpi.h"

CThostFtdcMdApi* pUserApi; // UserApi对象

char FRONT_ADDR[] = "tcp://180.168.146.187:10011";		// 前置地址
TThostFtdcBrokerIDType	BROKER_ID = "9999";			// 经纪公司代码
TThostFtdcInvestorIDType INVESTOR_ID = "059979";		// 投资者代码
TThostFtdcPasswordType  PASSWORD = "123456";			// 用户密码
char *ppInstrumentID[] = {"cu1710", "cu1801"};			// 行情订阅列表
int iInstrumentID = 2;						// 行情订阅数量
int iRequestID = 0;                                     // 请求编号

void main(void)
{
	pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();			// 创建UserApi

	CThostFtdcMdSpi* pUserSpi = new CMdSpi();
	pUserApi->RegisterSpi(pUserSpi);						// 注册事件类
	pUserApi->RegisterFront(FRONT_ADDR);					// connect
	pUserApi->Init();
	pUserApi->Join();
    pUserApi->Release();
}
