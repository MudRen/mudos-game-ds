// Room: /d/xiangyang/guofuyuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "郭府大院");
	set("long", @LONG
這裡是郭府的大院，當面一堵寬闊的白玉照壁，上書“忠
心報國”四個大字，地下是一色的青磚鋪地，四周種了幾棵大
樹，有幾個僕役正在院中灑掃，北面是郭府的客廳,。
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"guofugate",
		"north" : __DIR__"guofuting",
	]));
	set("coor/x", -520);
	set("coor/y", -480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}