inherit ROOM;
void create()
{
	set("short", "水草");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_10_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

