inherit ROOM;
void create()
{
	set("short", "骨龍妖霧");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_2_38",
	"west" : __DIR__"map_3_37",
	"south" : __DIR__"map_4_38",
	"east" : __DIR__"map_3_39",
	]));
		set("objects", ([
          __DIR__"npc/ents2" : 1, 
				]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

