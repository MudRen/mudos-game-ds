// Room: /u/s/slency/area/ugelan/royalty2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"皇宮內殿"NOR);
	set("long", 
"這裡是皇宮內殿大廳，不是普通人可以進得來的，這裡的裝潢十分\n""豪華，正前方坐著兩位穿著高貴的人，旁邊站著很多侍衛，你想這兩位\n""應該就是幽遮蘭城的國王與皇后了。\n"
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"royalty3",
]));
	set("no_clean_up", 0);
set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/king" : 1,
 __DIR__"npc/queen" : 1,
 __DIR__"npc/guard3" : 4, 
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
