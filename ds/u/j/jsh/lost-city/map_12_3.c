inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_4",
	"west" : __DIR__"map_12_2",
	"south" : __DIR__"map_13_3",
	"north" : __DIR__"map_11_3",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

