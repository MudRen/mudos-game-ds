inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_6_21",
	"west" : __DIR__"map_6_19",
	"north" : __DIR__"map_5_20",
	]));
	set("objects", ([
		__DIR__"npc/fetish":3,
		__DIR__"npc/fetish_wizard":2,
		__DIR__"npc/ents2":2,
		]));

	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

