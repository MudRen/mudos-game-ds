inherit ROOM;
void create()
{
	set("short", "���s��}");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_30",
	"west" : __DIR__"map_4_29",
	"south" : __DIR__"map_5_30",
	"east" : __DIR__"map_4_31",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

