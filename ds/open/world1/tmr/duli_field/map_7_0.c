inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_6_0",
	"east" : __DIR__"map_7_1",
	"south" : __DIR__"map_8_0",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

