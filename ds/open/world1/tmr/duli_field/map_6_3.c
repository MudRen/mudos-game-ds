inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_2",
	"north" : __DIR__"map_5_3",
	"east" : __DIR__"map_6_4",
	"south" : __DIR__"map_7_3",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

