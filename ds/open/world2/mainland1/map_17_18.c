inherit ROOM;
void create()
{
	set("short", "�w���L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_17_17",
	"south" : __DIR__"map_18_18",
	"north" : __DIR__"map_16_18",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

