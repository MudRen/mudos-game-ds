inherit ROOM;
void create()
{
	set("short", "小徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_33_28",
	"west" : __DIR__"map_33_26",
	]));
        set("objects" , ([
                __DIR__"npc/crazy-wildman.c" : 4 ,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

