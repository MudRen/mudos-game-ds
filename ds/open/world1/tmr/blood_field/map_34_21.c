inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_33_21",
	"west" : __DIR__"map_34_20",
	"south" : __DIR__"map_35_21",
	"east" : __DIR__"map_34_22",
	]));
			set("objects",([
			__DIR__"npc/fetish" : 2, 
			__DIR__"npc/fetish_wizard" : 2, 		
		]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

