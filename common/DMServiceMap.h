#pragma once

#include <map>
#include "ace/Thread_Mutex.h"

#define SERVICE_MAP_PATH "..//..//common//MsgRoute.json"

typedef struct msg_range
{
    msg_range():msg_start(0),msg_end(0){};
    int msg_start;
    int msg_end;
}MsgRange;

class DMServiceMap
{
public:
    static DMServiceMap* instance();
    
    DMServiceMap();
    
    //<server_name,server_id>
    std::map<std::string, int> service_map;
 
    //<server_name,msg_range>,��Ϣֱ��ӳ����ָ��cluster��node����
    std::map<int, MsgRange> message_map;  
private: 
    void load_cfg();

	static DMServiceMap* _instance;
    static ACE_Thread_Mutex _mutex_lock;
};
