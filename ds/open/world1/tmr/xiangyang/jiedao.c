// Room: /d/xiangyang/jiedao.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
這裡是襄陽城內有錢人的居住區。街道兩旁是一些豪華的
住宅，雖然襄陽歷經戰亂，但還有許多有錢人沒搬走，為堅守
襄陽城出錢出力。
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : __DIR__"minju1",
		"west"  : __DIR__"minju2",
		"north" : __DIR__"eastjie2",
	]));
	set("objects", ([
		__DIR__"npc/poorman" : 2,
	]));
	set("coor/x", -480);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

