inherit ROOM;
void create()
{
	set("short", "小徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_39_16",
	]));
        set("objects" , ([
                __DIR__"npc/wildman-captain.c" : 1 ,
                __DIR__"npc/wildman.c" : 2 ,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

