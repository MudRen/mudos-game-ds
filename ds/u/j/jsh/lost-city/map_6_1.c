inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_6_2",
	"west" : __DIR__"map_6_0",
	"south" : __DIR__"map_7_1",
	"north" : __DIR__"map_5_1",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

