inherit ROOM;
void create()
{
	set("short", "�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_1_13",
	"west" : __DIR__"map_1_11",
	"south" : __DIR__"map_2_12",
	]));
    set("objects", ([
        __DIR__"npc/orc_follower" : 4,
        __DIR__"npc/orc_thousand_leader" : 4,
    ]));

	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

