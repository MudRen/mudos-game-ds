#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"針灸室"NOR);

 set("long",@LONG
鼎鼎大名的天梟針灸室, 眼前數十個櫃子裡放著各式各樣
針灸的器具, 數百隻長針明晃晃的掛在牆上, 旁邊十來個小爐
子燒著小火, 一股令人作嘔的味道充斥在整個房間裡...
LONG
    );
 set("exits",([ "north":__DIR__"pill8",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
