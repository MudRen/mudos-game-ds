inherit ROOM;
void create()
{
	set("short", "臥室");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_16_34",
	"south" : __DIR__"map_17_33",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

