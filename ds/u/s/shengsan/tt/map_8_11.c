inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_8_10",
	"east" : __DIR__"map_8_12",
	"north" : __DIR__"map_7_11",
	"south" : __DIR__"map_9_11",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

