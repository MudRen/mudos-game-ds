inherit ROOM;
void create()
{
	set("short", "小徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_22_16",
	]));
        set("objects" , ([
                __DIR__"npc/corpse2.c" : 2 ,
                __DIR__"npc/lion.c" : 2
        ] ) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

