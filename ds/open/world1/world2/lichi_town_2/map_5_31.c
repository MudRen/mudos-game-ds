inherit ROOM;
void create()
{
	set("short", "倉庫");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_5_32",
	"south" : __DIR__"map_6_31",
	"north" : __DIR__"map_4_31",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

