inherit ROOM;
void create()
{
	set("short", "�s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_24",
	"west" : __DIR__"map_10_23",
	"north" : __DIR__"map_9_24",
	"east" : __DIR__"map_10_25",
	]));
    set("objects", ([
        __DIR__"npc/child.c" : 4,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

