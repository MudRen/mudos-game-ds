inherit ROOM;
void create()
{
	set("short", "旅館大廳");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_6_27",
	"north" : __DIR__"map_5_26",
	"west" : __DIR__"map_6_25",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

