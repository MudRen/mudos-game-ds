inherit ROOM;
void create()
{
	set("short", "�w���L");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_19_22",
	"north" : __DIR__"map_17_22",
	"east" : __DIR__"map_18_23",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

