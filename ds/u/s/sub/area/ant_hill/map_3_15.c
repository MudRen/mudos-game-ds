inherit ROOM;
void create()
{
	set("short", "�q�D");
        set("long", @LONG

LONG
    );
        set("objects", ([
        __DIR__"npc/hill_worker_20.c" : 3,
        ]) );
	set("exits",([
	"west" : __DIR__"map_3_14",
	"south" : __DIR__"map_4_15",
	"north" : __DIR__"map_2_15",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

