inherit ROOM;
void create()
{
	set("short", "郵局");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_7_37",
	"north" : __DIR__"map_5_37",
	"west" : __DIR__"map_6_36",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

