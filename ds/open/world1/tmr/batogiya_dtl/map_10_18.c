inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_10_17",
	"east" : __DIR__"map_10_19",
	]));
    set("objects", ([
        __DIR__"npc/obj/placard.c" : 1,
        __DIR__"npc/guard.c" : 5,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

