inherit ROOM;
void create()
{
	set("short", "淺海");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_6",
	"west" : __DIR__"map_4_4",
	"south" : __DIR__"map_5_5",
	"north" : __DIR__"map_3_5",
	"up":"/u/f/faceoff/area/seacoun39",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

