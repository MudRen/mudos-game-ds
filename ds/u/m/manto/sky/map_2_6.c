inherit ROOM;
void create()
{
	set("short", "舵主房");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_3_6",
	"west" : __DIR__"map_2_5",
	"east" : __DIR__"map_2_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

