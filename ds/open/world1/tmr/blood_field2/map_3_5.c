inherit ROOM;
void create()
{
	set("short", "骨龍妖霧");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_6",
	"west" : __DIR__"map_3_4",
	"south" : __DIR__"map_4_5",
	"north" : __DIR__"map_2_5",
	]));
	set("objects", ([
		__DIR__"npc/cat":2,
		__DIR__"npc/hulks":2,
		__DIR__"npc/wenigo":2,
		]));

	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

