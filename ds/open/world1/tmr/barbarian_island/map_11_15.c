inherit ROOM;
void create()
{
	set("short", "���Z�H���p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_10_15",
	"west" : __DIR__"map_11_14",
	"east" : __DIR__"map_11_16",
	"south" : __DIR__"map_12_15",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

