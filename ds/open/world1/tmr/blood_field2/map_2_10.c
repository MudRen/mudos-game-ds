inherit ROOM;
void create()
{
	set("short", "���s��}");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_11",
	"west" : __DIR__"map_2_9",
	]));
		set("objects", ([
		__DIR__"npc/hulks":2,
		__DIR__"npc/wenigo":2,
		__DIR__"npc/ents":2,
		]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

