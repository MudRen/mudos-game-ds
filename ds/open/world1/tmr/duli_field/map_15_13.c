inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_15_12",
	"north" : __DIR__"map_14_13",
	"east" : __DIR__"map_15_14",
	"south" : __DIR__"map_16_13",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

