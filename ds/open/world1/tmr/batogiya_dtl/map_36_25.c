inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_37_25",
	"east" : __DIR__"map_36_26",
	]));
    set("objects", ([
        __DIR__"npc/man.c" : 4,
    ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

