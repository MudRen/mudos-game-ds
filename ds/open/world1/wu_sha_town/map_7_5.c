inherit ROOM;
void create()
{
	set("short", "淺海");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_7_6",
	"west" : __DIR__"map_7_4",
	"south" : __DIR__"map_8_5",
	"north" : __DIR__"map_6_5",
	]));
 set("objects", ([__DIR__"../npc/carp" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

