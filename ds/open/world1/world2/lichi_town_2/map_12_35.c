inherit ROOM;
void create()
{
	set("short", "客廳");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_36",
	"south" : __DIR__"map_13_35",
	"north" : __DIR__"map_11_35",
	"west" : __DIR__"map_12_34",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

