inherit ROOM;
void create()
{
	set("short", "防具店");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_6_14",
	"south" : __DIR__"map_7_13",
	"west" : __DIR__"map_6_12",
	]));
	set("light",1);
	set("objects",([
	__DIR__"../npc/malo_researchman1_14":1,
	]));
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

