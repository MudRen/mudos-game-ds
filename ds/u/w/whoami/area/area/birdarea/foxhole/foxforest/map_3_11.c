inherit ROOM;
void create()
{
	set("short", "���� ");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_3_10",
	"south" : __DIR__"map_4_11",
	]));
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

