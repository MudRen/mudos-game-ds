inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_12",
	"north" : __DIR__"map_3_13",
	"east" : __DIR__"map_4_14",
	"south" : __DIR__"map_5_13",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

