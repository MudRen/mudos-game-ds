// Room: /u/s/sonicct/area/shop4.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"飯店"NOR);
	set("long", @LONG
這裡是一間由五星級的旅館打理的餐廳，費用當然是比較昂貴，徒
服務生的態度來看，是接受過高級的教育。而且這裡的食物也很好好的
。
LONG
	);
		set("light",1);
	set("no_clean_up", 0);
	set("room_type","hotel"); 
	set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"inn",
   ]));
	set("objects", ([ /* sizeof() == 1 */
 	 __DIR__"npc/keeper" : 1,
 	]));

	setup();
	replace_program(ROOM);
}
