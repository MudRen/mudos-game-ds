inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_8",
	"south" : __DIR__"map_3_9",
	"east" : __DIR__"map_2_10",
	"north" : __DIR__"map_1_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

