inherit ROOM;
void create()
{
	set("short", "石室");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_1_13",
	]));
        set("objects", ([
                __DIR__"npc/bandit3" : 1,
                __DIR__"npc/bandit2" : 1,
                __DIR__"npc/bandit" : 2,
        ]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

