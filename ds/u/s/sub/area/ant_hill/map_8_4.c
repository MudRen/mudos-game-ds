inherit ROOM;
void create()
{
	set("short", "通道");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_8_3",
	"south" : __DIR__"map_9_4",
	"east" : __DIR__"map_8_5",
	"north" : __DIR__"map_7_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

