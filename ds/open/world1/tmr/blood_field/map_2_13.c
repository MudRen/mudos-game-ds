inherit ROOM;
void create()
{
	set("short", "���s��}");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_1_13",
	"west" : __DIR__"map_2_12",
	"south" : __DIR__"map_3_13",
	"east" : __DIR__"map_2_14",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

