inherit ROOM;
void create()
{
	set("short", "�L�����-�X��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_7_7",
	"north" : __DIR__"map_5_7",
	"west" : __DIR__"map_6_6",
	"east" : __DIR__"map_6_8",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
