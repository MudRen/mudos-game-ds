inherit ROOM;
void create()
{
	set("short", "寒日洞三層");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_11",
	"north" : __DIR__"map_8_11",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

