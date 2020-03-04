#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIG"眠之森林-十字路口"NOR);
        set ("long", @LONG
嘔，你走到這，一股惡臭從你東方飄來...好像
是屍臭味...潮濕與悶熱散滿了整個空氣。在熱與濕
的雙重打壓下，你恨不的馬上離開這。
LONG);  
        
        set("exits", ([
        "south": __DIR__"",
        "north": __DIR__"road2",
        "west" : __DIR__"little1",
        "east" : __DIR__"humid",
        ]) );
        set("objects", ([
        __DIR__"npc/dog" : 1,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
