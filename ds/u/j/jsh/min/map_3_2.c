inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_2",
	"east" : __DIR__"map_3_3",
	"north" : __DIR__"map_2_2",
	"west" : __DIR__"map_3_1",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

