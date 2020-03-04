inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_3",
	"west" : __DIR__"map_3_1",
	"south" : __DIR__"map_4_2",
	"north" : __DIR__"map_2_2",
	]));
	set("objects", ([
		__DIR__"npc/fetish":2,
		__DIR__"npc/cat":2,
		__DIR__"npc/fetish_wizard":2,
		]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

