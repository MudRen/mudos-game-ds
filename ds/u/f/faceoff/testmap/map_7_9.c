inherit ROOM;
void create()
{
	set("short", "海流");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_8",
	]));
      set("objects", ([__DIR__"npc/clam" : 2,
       ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

