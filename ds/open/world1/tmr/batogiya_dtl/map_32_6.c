inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_32_5",
	"north" : __DIR__"map_31_6",
	]));
    set("objects", ([
        __DIR__"npc/bigboar.c" : 3,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

