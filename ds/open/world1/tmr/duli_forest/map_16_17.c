inherit ROOM;
void create()
{
	set("short", "小路");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_15_17",
	"south" : __DIR__"map_17_17",
	]));
	set("outdoors","land");
        set("objects",([
                __DIR__"npc/bandit":2,
                  __DIR__"npc/bandit2":2,
        ]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

