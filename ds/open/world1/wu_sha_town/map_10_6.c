inherit ROOM;
void create()
{
	set("short", "淺海");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_7",
	"west" : __DIR__"map_10_5",
	"south" : __DIR__"map_11_6",
	]));
        set("objects", ([ __DIR__"../npc/shark" : 2,
          "/open/world1/obj/corpse" : 1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

