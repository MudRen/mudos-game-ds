inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_14_8",
	"west" : __DIR__"map_14_6",
	"south" : __DIR__"map_15_7",
	"north" : __DIR__"map_13_7",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

