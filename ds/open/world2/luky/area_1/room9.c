// Modify with AreaMaker1.0
// Room9.c

inherit ROOM;

void create()
{
	set("short","山腳旁");
	set("long", @LONG
你走在山腳旁的小路上，兩旁的雜草明顯的少了許多，取而代之
的是一堆堆的碎石頭。這裡的風似乎永遠不會停止  你的耳朵除了風
聲似乎已經聽不到任何聲音了。
LONG
	);
	set("exits", ([
		"east": __DIR__"room10",
		"south": __DIR__"room19",
		"southwest": __DIR__"room18",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

