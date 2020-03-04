inherit ROOM;
void create()
{
	set("short", "骨龍妖霧");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_4",
	"west" : __DIR__"map_3_2",
	"south" : __DIR__"map_4_3",
	"north" : __DIR__"map_2_3",
	]));
		set("objects", ([
		__DIR__"npc/cat":2,
		__DIR__"npc/fetish_wizard":2,
		__DIR__"npc/hulks":2,
		]));

	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

