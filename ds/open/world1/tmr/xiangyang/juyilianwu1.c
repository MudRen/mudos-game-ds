// Room: /open/world1/tmr/xiangyang/juyilianwu1.c

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
這裡是聚義館中用來練功的地方。有幾個人正在專心致致
地練武，有幾個手持兵器，在互相拆招。身法靈動，猶如穿花
蝴蝶一般，你不禁看花了眼，別的人則坐在地上的蒲團上苦練
內力。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"juyiyuan",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -501,
  "x" : -529,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
