inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_8_30",
	"west" : __DIR__"map_9_29",
	"south" : __DIR__"map_10_30",
	"east" : __DIR__"map_9_31",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

