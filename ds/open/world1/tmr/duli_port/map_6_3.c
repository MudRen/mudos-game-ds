inherit ROOM;
void create()
{
	set("short", "杜尼港-街道");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_2",
	"east" : __DIR__"map_6_4",
	]));
	set("outdoors","land");
        set("objects",([
                __DIR__"npc/police":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

