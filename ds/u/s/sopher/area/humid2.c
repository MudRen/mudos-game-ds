#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", YEL"通往沼澤地的通路上"NOR);
        set ("long", @LONG
你一股無力感自你心頭浮現，你的腳步慢慢的
沈重了起來，喝向陷入了黑暗的絕境，這一片沼澤
真的是太詭異啦！
LONG);  
        
        set("exits", ([
        "west" : __DIR__"humid",
        "east" : __DIR__"humid3",
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
