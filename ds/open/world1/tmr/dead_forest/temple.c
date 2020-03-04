// File: /d/dead_forest/temple.c
// Updated by tmr (Fri Feb 20 22:02:43 2004)

inherit ROOM;

void create()
{
	  set("short", "古廟");
	  set("long", @LONG
這是一座廢棄有數十年之久的古廟，棟樑柱子上都已經佈滿了
蜘蛛網，廟內供奉的數尊神像也滿是灰塵，上頭的金漆也幾乎都因
年久而剝落下來了，可見已經很久沒有人來過了。
LONG
	  );
	  set("exits", ([ /* sizeof() == 1 */
	"out" : __DIR__"map_16_19",
]));
	  set( "objects" , ([
	  	  __DIR__"npc/yang-xiao" : 1,
	  	  ]) );

	setup();
	  replace_program(ROOM);
}
