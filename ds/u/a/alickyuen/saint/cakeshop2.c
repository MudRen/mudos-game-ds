// updated
#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", HIC"ST．CakeShop＠Kitchen"NOR);
	set("long", @LONG
這裡是蛋糕店內的廚房，香氣比外面更加濃，四處看看，你發現了種
種蛋糕，麵包等你食品。你看著也感到有些餓了。但可惜是不能吃，但不
用灰心，找找看....可能會有意外收獲呢.....
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"cakeshop",
]));
  set("objects",([
 __DIR__"npc/obj/chocolatecake":1,
__DIR__"npc/obj/berrycake":1,
__DIR__"npc/obj/mangocake":1,
 ]));
set("light",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
