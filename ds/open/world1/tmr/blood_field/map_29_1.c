inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_28_1",
	"west" : __DIR__"map_29_0",
	"east" : __DIR__"map_29_2",
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

