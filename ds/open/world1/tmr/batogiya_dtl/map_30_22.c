inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_31_22",
	"west" : __DIR__"map_30_21",
	"east" : __DIR__"map_30_23",
	]));
    set("objects", ([
        __DIR__"npc/boar.c" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

