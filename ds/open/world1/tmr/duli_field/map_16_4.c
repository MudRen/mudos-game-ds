inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_16_3",
	"north" : __DIR__"map_15_4",
	"east" : __DIR__"map_16_5",
	"south" : __DIR__"map_17_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

