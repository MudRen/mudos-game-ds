inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_30_36",
	"west" : __DIR__"map_29_35",
	"north" : __DIR__"map_28_36",
	]));
    set("objects", ([
        __DIR__"npc/snake.c" : 5,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

