inherit ROOM;
void create()
{
	set("short", "寒日洞二層");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_5_9",
	"north" : __DIR__"map_3_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

