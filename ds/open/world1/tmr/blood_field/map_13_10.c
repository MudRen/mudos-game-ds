inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_12_10",
	"west" : __DIR__"map_13_9",
	"south" : __DIR__"map_14_10",
	"east" : __DIR__"map_13_11",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

