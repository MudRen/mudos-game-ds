inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_5_8",
	"north" : __DIR__"map_4_9",
	"south" : __DIR__"map_6_9",
	"east" : __DIR__"map_5_10",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

