inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_12_14",
	"north" : __DIR__"map_11_15",
	"east" : __DIR__"map_12_16",
	"south" : __DIR__"map_13_15",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

