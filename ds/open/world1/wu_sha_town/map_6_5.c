inherit ROOM;
void create()
{
	set("short", "海流");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_7_5",
	"north" : __DIR__"map_5_5",
	]));
 set("objects", ([__DIR__"../npc/fish" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

