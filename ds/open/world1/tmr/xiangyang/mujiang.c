// Room: /d/xiangyang/mujiang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "木匠鋪");
	set("long", @LONG
這是一家簡陋的木匠鋪，一個中年木匠正蹲在地上釘東西。
值此亂世，木匠們也只好制作些刀槍棍棒什麼的以養家糊口。
地上和牆角凌亂地堆放著一些木劍，木刀，木棍什麼的，還有
幾件像鋸子，刨子一類的木匠工具。
LONG );
	set("exits", ([
		"north" : __DIR__"eastjie3",
	]));
	set("objects", ([
//         __DIR__"npc/mujiang" : 1,
	]));
	set("coor/x", -470);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
