inherit ROOM;
void create()
{
	set("short", "地下大墳場-大廳");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_9_13",
	"north" : __DIR__"map_7_13",
	"west" : __DIR__"map_8_12",
	"east" : __DIR__"map_8_14",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

