inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_5",
	"west" : __DIR__"map_3_3",
	"south" : __DIR__"map_4_4",
	"north" : __DIR__"map_2_4",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

