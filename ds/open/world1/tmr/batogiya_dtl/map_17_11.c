inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_18_11",
	"west" : __DIR__"map_17_10",
	"north" : __DIR__"map_16_11",
	]));
    set("objects", ([
        __DIR__"npc/obj/branche.c" : 1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

