inherit ROOM;
void create()
{
	set("short", "林道");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_3_8",
	"west" : __DIR__"map_2_7",
	"east" : __DIR__"map_2_9",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

