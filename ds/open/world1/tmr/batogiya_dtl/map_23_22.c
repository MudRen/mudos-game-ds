inherit ROOM;
void create()
{
	set("short", "枯木");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_24_22",
	"west" : __DIR__"map_23_21",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

