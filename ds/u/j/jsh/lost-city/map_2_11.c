inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_12",
	"west" : __DIR__"map_2_10",
	"south" : __DIR__"map_3_11",
	"north" : __DIR__"map_1_11",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
