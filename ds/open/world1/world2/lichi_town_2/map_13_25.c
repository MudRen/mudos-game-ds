inherit ROOM;
void create()
{
	set("short", "舞台");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_13_26",
	"north" : __DIR__"map_12_25",
	"west" : __DIR__"map_13_24",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

