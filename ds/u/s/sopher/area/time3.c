#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIC"HANS集團時空管理處通道"NOR);
        set ("long", @LONG
這裡四周一片死寂，隱隱約約聽到機器嗡嗡作響。
前方就是十字路口了，走到這，已經是此處的身處，因
此鮮少看到守衛，偶而你會聽見巡邏的腳步聲。
LONG);  
        set("exits", ([
        "north" : __DIR__"time2",
        "south" :__DIR__"time4",
         ]) );
        
        set("light",1);
        setup();
        replace_program(ROOM);
}
