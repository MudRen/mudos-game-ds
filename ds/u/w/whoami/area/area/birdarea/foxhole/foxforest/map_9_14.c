inherit ROOM;
void create()
{
	set("short", "薄霧 ");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_9_13",
	"south" : __DIR__"map_10_14",
	"north" : __DIR__"map_8_14",
	]));
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

