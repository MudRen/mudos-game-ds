inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_2",
	"west" : __DIR__"map_12_0",
	"south" : __DIR__"map_13_1",
	"north" : __DIR__"map_11_1",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

