inherit ROOM;
void create()
{
	set("short", "銀行");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_17_24",
	"north" : __DIR__"map_16_23",
	"west" : __DIR__"map_17_22",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

