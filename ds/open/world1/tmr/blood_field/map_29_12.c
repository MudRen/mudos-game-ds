inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_28_12",
	"west" : __DIR__"map_29_11",
	"south" : __DIR__"map_30_12",
	"east" : __DIR__"map_29_13",
	]));
	set("outdoors","land");
				set("objects",([
			__DIR__"npc/fetish" : 2, 
			__DIR__"npc/fetish_wizard" : 2, 		
		]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

