inherit ROOM;
void create()
{
	set("short", "淺灘");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_3",
	"west" : __DIR__"map_2_1",
	]));
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

