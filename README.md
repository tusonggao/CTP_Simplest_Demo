# CTP_Simplest_Demo
上期所CTP接口控制台应用程序最精简示例

* CTP_md_demo 对应行情订阅；
* CTP_trade_demo 对应订单提交；
* CTP_Api为CTP接口所需的头文件和库文件，可以从[CTP官网](http://www.sfit.com.cn/5_2_DocumentDown.htm)下载。

编译时注意：
1. CTP_md_demo要链接到thostmduserapi.lib
2. CTP_trade_demo要链接到thosttraderapi.lib
3. 注意windows版本64位和32位的区别，一定要与编译器对应，否则编译可能会出现 “LNK2019：无法解析的外部符号”的错误。我这里上传的是windows版本32位的。




