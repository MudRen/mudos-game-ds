inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_13_9",
	"west" : __DIR__"map_13_7",
	"south" : __DIR__"map_14_8",
	"north" : __DIR__"map_12_8",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
