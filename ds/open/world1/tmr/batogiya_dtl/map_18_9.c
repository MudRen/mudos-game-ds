inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_19_9",
	"north" : __DIR__"map_17_9",
	"east" : __DIR__"map_18_10",
	]));
    set("objects", ([
        __DIR__"npc/man.c" : 4,
    ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

