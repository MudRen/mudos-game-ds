inherit ROOM;
void create()
{
	set("short", "���ͦ�");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_14",
	"north" : __DIR__"map_6_15",
	"south" : __DIR__"map_8_15",
	"east" : __DIR__"map_7_16",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

