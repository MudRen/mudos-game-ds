inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_2",
	"east" : __DIR__"map_10_3",
	"north" : __DIR__"map_9_2",
	"west" : __DIR__"map_10_1",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

