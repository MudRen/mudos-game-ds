inherit ROOM;
void create()
{
    set("short", "�Ͳ���");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_1",
	"south" : __DIR__"map_3_2",
	"east" : __DIR__"map_2_3",
	"north" : __DIR__"map_1_2",
	]));
    set("objects", ([ __DIR__"npc/hill_queen_5" :1, ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

