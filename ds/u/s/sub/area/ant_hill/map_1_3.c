inherit ROOM;
void create()
{
	set("short", "通道");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_1_2",
	"south" : __DIR__"map_2_3",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

