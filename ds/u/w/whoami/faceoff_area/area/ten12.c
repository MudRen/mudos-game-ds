#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","茅屋");

 set("long",@LONG
你看到這裡有一位老人正在唉聲嘆氣, 不知道有什麼困難
, 你抬頭看見了一個青銅製成的梟像, 難道這個老人跟天梟教
有什麼關連?
LONG
    );
 set("exits",([	"east":__DIR__"ten11",
    ]));
 set("objects", ([__DIR__"npc/old_man" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}