inherit ROOM;
void create()
{
	set("short", "巷道");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_1_26",
	"south" : __DIR__"map_2_25",
	"west" : __DIR__"map_1_24",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

