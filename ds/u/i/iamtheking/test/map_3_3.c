inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_3_2",
	"north" : __DIR__"map_2_3",
	"south" : __DIR__"map_4_3",
	"east" : __DIR__"map_3_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

