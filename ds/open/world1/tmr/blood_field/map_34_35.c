inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_33_35",
	"west" : __DIR__"map_34_34",
	"south" : __DIR__"map_35_35",
	"east" : __DIR__"map_34_36",
	]));
			set("objects",([
			__DIR__"npc/fetish" : 2, 
			__DIR__"npc/cat" : 2, 		
		]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

