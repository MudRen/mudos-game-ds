#include <ansi2.h>
inherit ROOM;

void create()
{
	set("short", HIB"夜神蒼天"NOR);
	set("long", @LONG
這個地方就是傳說中夜神的出沒地點。雖然有點漆黑，但是卻讓
人有一種很安心的感覺。再這裡可以隨你高興的做些你想做的事情。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("valid_startroom", 1);
	set("objects", ([ /* sizeof() == 1 */
  		__DIR__"lion.c" : 1,
	]));
	set("exits", ([ /* sizeof() == 5 */
  		"enter" : __DIR__"workroom1",
  		//"east" : __DIR__"pwest/path1.c",
  		"wizroom" : "/d/wiz/hall1",
  		"south" : __DIR__"workroom2",
  		//"down" : __DIR__"area/h_d.c",
	]));

	setup();
	call_other("/obj/board/sdo_b", "sdo");
}
