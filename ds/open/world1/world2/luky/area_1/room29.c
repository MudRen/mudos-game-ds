// Modify with AreaMaker1.0
// Room29.c

inherit ROOM;

void create()
{
	set("short","樹林邊緣");
	set("long", @LONG
這裡地上的雜草顯然比較稀疏，東邊有一個大平原，這裡的風十
分強勁，甚至讓人覺得連走路都有阻力。你發現風是由東北向西南吹
的。
LONG
	);
	set("exits", ([
		"north": __DIR__"room19",
		"east": __DIR__"room30",
		"south": __DIR__"room39",
		"west": __DIR__"room28",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

