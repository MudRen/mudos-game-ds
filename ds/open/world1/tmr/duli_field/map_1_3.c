inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_1_2",
	"north" : __DIR__"map_0_3",
	"east" : __DIR__"map_1_4",
	"south" : __DIR__"map_2_3",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

