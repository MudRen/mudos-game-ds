inherit ROOM;
void create()
{
	set("short", "���s��}");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_17",
	"west" : __DIR__"map_4_15",
	"south" : __DIR__"map_5_16",
	"north" : __DIR__"map_3_16",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
