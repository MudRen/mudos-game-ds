inherit ROOM;
void create()
{
	set("short", "������-��D");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_15_10",
	"north" : __DIR__"map_13_10",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

