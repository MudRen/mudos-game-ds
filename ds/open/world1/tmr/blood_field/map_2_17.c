inherit ROOM;
void create()
{
	set("short", "骨龍妖霧");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_1_17",
	"west" : __DIR__"map_2_16",
	"south" : __DIR__"map_3_17",
	"east" : __DIR__"map_2_18",
	]));
	set("outdoors","land");
			set("objects", ([
          __DIR__"npc/cat" : 2, 
          __DIR__"npc/fetish_wizard" : 2, 
	]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

