inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_6",
	"east" : __DIR__"map_7_8",
	"north" : __DIR__"map_6_7",
	"south" : __DIR__"map_8_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

