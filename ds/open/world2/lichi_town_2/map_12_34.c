inherit ROOM;
void create()
{
	set("short", "���U");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_35",
	"south" : __DIR__"map_13_34",
	"north" : __DIR__"map_11_34",
	"west" : __DIR__"map_12_33",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

