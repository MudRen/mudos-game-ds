
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"天梟教"NOR"前院");

 set("long",@LONG 
你來到天梟教的前院, 與其說是前院倒不如說是鳥園還比較
適合, 在這裡的鳥比剛才看見的要多上好幾倍, 而且種類也變多
了, 他們全圍在石梟旁, 你心中暗想天梟不愧是天梟, 果然是鳥
中之王。
LONG
    );
//鳥中之王....好鳥啊-0-... 
 set("exits",(["east":__DIR__"bird15",
               "west":__DIR__"bird13",
               "north":__DIR__"bird22",
               
     ]));
 
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           

