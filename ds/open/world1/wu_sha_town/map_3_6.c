inherit ROOM;
void create()
{
	set("short", "水草");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_3_5",
	"south" : __DIR__"map_4_6",
	]));
set("objects", ([__DIR__"../npc/tunny" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

