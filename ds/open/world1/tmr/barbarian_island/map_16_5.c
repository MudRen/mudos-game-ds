inherit ROOM;
void create()
{
	set("short", "野蠻人的小屋");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_15_5",
	"east" : __DIR__"map_16_6",
	]));
        set("objects",([
                __DIR__"npc/barbarian_village_head":1,
        ]));

	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

