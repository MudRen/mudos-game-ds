inherit ROOM;
void create()
{
	set("short", "�x�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_14_33",
	"south" : __DIR__"map_15_32",
	"north" : __DIR__"map_13_32",
	"west" : __DIR__"map_14_31",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

