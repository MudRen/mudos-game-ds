inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_16",
	"east" : __DIR__"map_3_17",
	"north" : __DIR__"map_2_16",
	"west" : __DIR__"map_3_15",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

