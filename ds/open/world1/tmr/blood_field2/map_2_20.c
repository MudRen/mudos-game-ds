inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_21",
	"west" : __DIR__"map_2_19",
	"south" : __DIR__"map_3_20",
	"north" : __DIR__"map_1_20",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

