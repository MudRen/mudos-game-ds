inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_10",
	"east" : __DIR__"map_3_11",
	"north" : __DIR__"map_2_10",
	"west" : __DIR__"map_3_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

