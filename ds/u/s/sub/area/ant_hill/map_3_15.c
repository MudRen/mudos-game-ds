inherit ROOM;
void create()
{
	set("short", "通道");
        set("long", @LONG

LONG
    );
        set("objects", ([
        __DIR__"npc/hill_worker_20.c" : 3,
        ]) );
	set("exits",([
	"west" : __DIR__"map_3_14",
	"south" : __DIR__"map_4_15",
	"north" : __DIR__"map_2_15",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

