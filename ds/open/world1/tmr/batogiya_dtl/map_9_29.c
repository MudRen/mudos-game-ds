inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_29",
	"west" : __DIR__"map_9_28",
	"east" : __DIR__"map_9_30",
	]));
    set("objects", ([
        __DIR__"npc/villager.c" : 3,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

