inherit ROOM;
void create()
{
	set("short", "通道");
        set("long", @LONG

LONG
);
        set("objects", ([
        __DIR__"npc/anthill_armyant_36.c" : 3,
        ]) );
	set("exits",([
	"west" : __DIR__"map_8_2",
	"east" : __DIR__"map_8_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

