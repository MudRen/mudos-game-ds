#include <room.h>
inherit ROOM;
void create()
{
 set("short","二少堂主寢室");
 set("long",@LONG
這房間的擺設和大少堂主的寢室真是有天壤之別, 豪華異常,
奢侈無比. 桌上全是大魚大肉和上好美酒, 你雖然有點想十指大
動, 不過還是儘量壓抑下來. 有個人穿著華麗的在花天酒地, 對
著身邊兩三名侍女說些瘋言瘋語.
LONG
    );
 set("exits",([ "south":__DIR__"inroom43",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
