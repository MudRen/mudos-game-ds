inherit ROOM;
void create()
{
	set("short", "�j�U");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_13_10",
	"north" : __DIR__"map_12_9",
	]));
    set("objects", ([
        __DIR__"npc/orc_commander" : 4,
    ]));

	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

