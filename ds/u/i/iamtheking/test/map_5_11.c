inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_5_10",
	"north" : __DIR__"map_4_11",
	"south" : __DIR__"map_6_11",
	"east" : __DIR__"map_5_12",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

