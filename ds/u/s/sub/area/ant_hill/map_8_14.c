inherit ROOM;
void create()
{
	set("short", "通道");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_8_13",
	"south" : __DIR__"map_9_14",
	]));
        set("objects", ([
        __DIR__"npc/hill_armyant_34" : 2,
        ]) ); 
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

