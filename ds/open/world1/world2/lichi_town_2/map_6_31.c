inherit ROOM;
void create()
{
	set("short", "�ܮw");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_6_32",
	"south" : __DIR__"map_7_31",
	"north" : __DIR__"map_5_31",
	"west" : __DIR__"map_6_30",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

