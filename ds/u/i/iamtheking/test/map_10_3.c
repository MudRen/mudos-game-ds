inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_10_2",
	"north" : __DIR__"map_9_3",
	"south" : __DIR__"map_11_3",
	"east" : __DIR__"map_10_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

