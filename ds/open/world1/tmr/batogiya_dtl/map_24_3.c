inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_24_2",
	"north" : __DIR__"map_23_3",
	"east" : __DIR__"map_24_4",
	]));
    set("objects", ([
        __DIR__"npc/rabbit.c" : 5,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
