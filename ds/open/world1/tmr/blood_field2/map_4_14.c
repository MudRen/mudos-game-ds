inherit ROOM;
void create()
{
	set("short", "���s��}");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_15",
	"west" : __DIR__"map_4_13",
	"south" : __DIR__"map_5_14",
	"north" : __DIR__"map_3_14",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
