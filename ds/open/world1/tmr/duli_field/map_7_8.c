inherit ROOM;
void create()
{
	set("short", "岩穴入口");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_8_8",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

