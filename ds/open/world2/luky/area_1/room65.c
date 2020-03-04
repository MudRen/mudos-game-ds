// Modify with AreaMaker1.0
// Room65.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你一走到這裡就看到了一個棄墳，墳墓已經很久沒清理了所以不
容易發現。你很自傲自己有如此犀利的觀察力，雖然心中有些毛毛的
，不過你還是走上前去參拜了一會兒。旁邊還有一個CD盒，似乎是李
玟的第一張專輯，不知道是誰丟在這裡的。
LONG
	);
	set("exits", ([
		"north": __DIR__"room55",
		"south": __DIR__"room75",
		"northwest": __DIR__"room54",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

