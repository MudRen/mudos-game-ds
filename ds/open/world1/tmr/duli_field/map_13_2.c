inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_13_1",
	"north" : __DIR__"map_12_2",
	"east" : __DIR__"map_13_3",
	"south" : __DIR__"map_14_2",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

