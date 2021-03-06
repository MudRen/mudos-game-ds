// Room: /d/xiangyang/guofuhuayuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "郭府後花園");
	set("long", @LONG
這裡是郭府的後花園，園內假山林立，西邊種著一些青竹，
東邊是幾棵枝葉茂盛的木筆花樹。你一走進來，就聞到一陣陣
清新的、淡淡的花香。
LONG );
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"guofuwoshi",
		"west"  : __DIR__"guofukefang",
		"south" : __DIR__"guofuting",
		"north" : __DIR__"guofushufang",
	]));
	set("objects", ([
		__DIR__"npc/huang" : 1,
	]));
	set("coor/x", -520);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}