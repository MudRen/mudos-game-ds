inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_10_21",
	"east" : __DIR__"map_10_23",
	]));
    set("objects", ([
        __DIR__"npc/gang.c" : 1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

