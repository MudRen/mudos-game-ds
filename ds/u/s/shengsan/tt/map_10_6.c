inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_10_5",
	"east" : __DIR__"map_10_7",
	"north" : __DIR__"map_9_6",
	"south" : __DIR__"map_11_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

