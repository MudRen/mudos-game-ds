// Modify with AreaMaker1.0
// Room36.c

inherit ROOM;

void create()
{
	set("short","大樹下");
	set("long", @LONG
這裡有棵大樹，附近的樹沒有一棵像這棵樹長的如此高大。樹下
有個小供桌，上面有個香爐，似乎是用來供奉這個神木的。旁邊還有
些桌椅，供香客們休憩之用。
LONG
	);
	set("exits", ([
		"north": __DIR__"room26",
		"east": __DIR__"room37",
		"south": __DIR__"room46",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

