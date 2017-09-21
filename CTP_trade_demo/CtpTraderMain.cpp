#include ".\ThostTraderApi\ThostFtdcTraderApi.h"
#include "TraderSpi.h"

CThostFtdcTraderApi* pUserApi;  // UserApi对象

char  FRONT_ADDR[] = "tcp://180.168.146.187:10001";		// 前置地址
TThostFtdcBrokerIDType	BROKER_ID = "9999";				// 经纪公司代码
TThostFtdcInvestorIDType INVESTOR_ID = "059979";		// 投资者代码
TThostFtdcPasswordType  PASSWORD = "Krazy49";			// 用户密码
TThostFtdcInstrumentIDType INSTRUMENT_ID = "CF801";	    // 合约代码
//TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Sell;	// 买卖方向
TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Buy;     // ping jin THOST_FTDC_OF_CloseToday  THOST_FTDC_OF_Close
TThostFtdcPriceType	LIMIT_PRICE = 15350;  // 38850;		 // 价格
int iRequestID = 0;   // 请求编号

void insertRequest()
{
    pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// 初始化创建UserApi
    CTraderSpi* pUserSpi = new CTraderSpi();
    pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// 注册事件类
    pUserApi->SubscribePublicTopic(THOST_TERT_QUICK);				// 注册公有流
    pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK);				// 注册私有流
    pUserApi->RegisterFront(FRONT_ADDR);							// connect
    pUserApi->Init();
    pUserApi->Join();
    pUserApi->Release();
}

int main(int argc, char* argv[])
{
     insertRequest();
     return 0;
}
