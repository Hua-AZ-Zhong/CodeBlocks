// Structure Definition
struct POMP {
    int TranId;                 // 交易流水号，固定长6位
    char TerId[9];              // POS终端号，固定长8位
    char CardId[20];            // 卡号，变长16~19位
    char ProName[11];           // 产品名称
    char ModName[21];           // 模块名称
    char NodeId[3];             // 节点号, 固定长2位
    char TxnID[3];              // 交易码，固定长2位
    char TimeType[3];           // 记录时点类型，固定长2位
    char TxnDateTime[24];       // 记录时点时间戳，固定长23位，YYYY-MM-DD HH:mm:ss.ms, ms记录到3位数字，取系统本地时间（北京时间），时间类型为24小时制
    char LinkSysName[21];       // 互联系统（模块）名称，同模块名称的处理
    char ReturnCode[11];        // 交易返回码
    char ReturnMsg[1001];       // 交易异常信息
    char SucFlag[2];            // 技术成功标识
    char costtime[7];           // 交易耗时
};

// Function Declaration
int OTraceDebug(FILE *fp, struct POMP *pm, int flashFlag);
void GetTimeSys(char *str);
void GetSysDate(char *sysDate);
void GetTimeStamp(char *timeStamp);
void getCostTime(char *costTime);
void getModuleName(char *mainArgv, char *moduleName);
void setData(struct POMP *pm, char *mainArgv, char *timeType);
