inherit ROOM;
void create()
{
	set("short", "狐穴");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_14_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

