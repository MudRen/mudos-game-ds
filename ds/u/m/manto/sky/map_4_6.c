inherit ROOM;
void create()
{
	set("short", "堂主房");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_5_6",
	"west" : __DIR__"map_4_5",
	"east" : __DIR__"map_4_7",
	"north" : __DIR__"map_3_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

