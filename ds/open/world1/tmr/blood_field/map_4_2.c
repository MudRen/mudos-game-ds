inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_2",
	"west" : __DIR__"map_4_1",
	"south" : __DIR__"map_5_2",
	"east" : __DIR__"map_4_3",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
