inherit ROOM;
void create()
{
	set("short", "�L�����-�X��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_9_2",
	"north" : __DIR__"map_7_2",
	"west" : __DIR__"map_8_1",
	"east" : __DIR__"map_8_3",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

