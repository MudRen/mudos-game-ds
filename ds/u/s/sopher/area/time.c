#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIC"HANS集團時空裂縫管理閘門"NOR);
        set ("long", @LONG
前方就是時空裂縫了！由於這項計畫進行得相當隱密
。因此知道此地方的人更是少之又少。閘門前有兩位管理
員，正在清查穿越查門者的身份和資料。
LONG);  
        
        set("exits", ([
        "north" : __DIR__"timeroom",
        "south" : __DIR__"time2",
        ]) );
        set("objects", ([
        __DIR__"npc/admin" : 2,
        ]) );
        set("light",1);
        setup();
        replace_program(ROOM);
}
