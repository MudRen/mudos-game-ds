// Modify with AreaMaker1.0
// Room87.c

inherit ROOM;

void create()
{
	set("short","樹林邊");
	set("long", @LONG
這裡有些動物的足跡  似乎有不少野獸出沒於此。也難怪，因為
北邊有個小池塘，東邊是個草原，西邊又是樹林，各種生態資源豐富
，動物們自然會呼朋引伴前來此處覓食了。
LONG
	);
	set("exits", ([
		"east": __DIR__"room88",
		"west": __DIR__"room86",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

