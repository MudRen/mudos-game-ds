#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIC"HANS集團時空管理處正門口"NOR);
        set ("long", @LONG
這裡是通往時空裂縫的通道上！由於這項計畫進行得相當
隱密。因此知道此地方的人更是少之又少。閘門前有兩位管理
員，正在清查穿越查門者的身份和資料。
LONG);  
        
        set("exits", ([
        "north" : __DIR__"time",
        "south" :__DIR__"time3",
         ]) );
        
        set("light",1);
        setup();
        replace_program(ROOM);
}
