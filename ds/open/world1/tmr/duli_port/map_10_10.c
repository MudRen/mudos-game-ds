inherit ROOM;
void create()
{
	set("short", "中央廣場");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_10",
	"west" : __DIR__"map_10_9",
	"north" : __DIR__"map_9_10",
	"east" : __DIR__"map_10_11",
	]));
	set("outdoors","land");

        set("objects",([
                 __DIR__"npc/police":1,
                 "/obj/stake":3,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

