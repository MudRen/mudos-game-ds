inherit ROOM;
void create()
{
	set("short", "寒日洞二層");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_4",
	"east" : __DIR__"map_6_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

