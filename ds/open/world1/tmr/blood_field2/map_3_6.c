inherit ROOM;
void create()
{
	set("short", "���s��}");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_7",
	"west" : __DIR__"map_3_5",
	"south" : __DIR__"map_4_6",
	"north" : __DIR__"map_2_6",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

