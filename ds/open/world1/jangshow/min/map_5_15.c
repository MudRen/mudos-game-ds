inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_6_15",
	"east" : __DIR__"map_5_16",
	"north" : __DIR__"map_4_15",
	"west" : __DIR__"map_5_14",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

