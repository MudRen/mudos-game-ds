inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_12",
	"west" : __DIR__"map_10_10",
	"south" : __DIR__"map_11_11",
	"north" : __DIR__"map_9_11",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

