#include <room.h>
inherit ROOM;
void create()
{
 set("short","霞雁閣");
 set("long",@LONG
這算是滿大的一間房間, 你打量了四周, 佈置雖然差了一點, 
不過卻大得多了, 大概可以睡四五個人沒問題. 你看到這邊已經
有三個武林人士在這邊休息. 有兩個是雷霆拳門的人, 另一個則
是持刀的不知名人士. 如果你要休息, 最好先和他們打探一番.  
LONG
    );
 set("exits",([ "south":__DIR__"inroom27",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}
