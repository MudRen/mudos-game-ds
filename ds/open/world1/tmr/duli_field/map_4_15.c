inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_14",
	"north" : __DIR__"map_3_15",
	"east" : __DIR__"map_4_16",
	"south" : __DIR__"map_5_15",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
