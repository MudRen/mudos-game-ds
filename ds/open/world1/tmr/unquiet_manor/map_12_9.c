inherit ROOM;
void create()
{
	set("short", "�L�����-�X��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_13_9",
	"north" : __DIR__"map_11_9",
	"west" : __DIR__"map_12_8",
	"east" : __DIR__"map_12_10",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

