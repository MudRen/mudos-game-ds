#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"藥材室"NOR);

 set("long",@LONG
鼎鼎大名的天梟藥材室, 話說這裡雖然只能買到較為基本
的藥材, 但仍然是不可多得的好地方, 之所以要用買的是因為
天梟最近財政拮据....
LONG
    );
 set("exits",([ "north":__DIR__"pill8",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
