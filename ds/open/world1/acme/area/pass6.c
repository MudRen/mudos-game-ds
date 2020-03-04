// Room: /u/a/acme/area/pass6.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這裡是天山的山腳下，往天山延伸而去的是一條崎嶇的山路，青萃的
天山，遠遠望去，令人心曠神怡，只想在此多待一會，瞧瞧這雄偉的高山
。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : COMINGING_PAST"area/river3.c" ,
  "eastup" : __DIR__"pass5",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
