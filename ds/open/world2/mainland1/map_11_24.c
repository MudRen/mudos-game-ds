inherit ROOM;
void create()
{
	set("short", "�w���L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_23",
	"south" : __DIR__"map_12_24",
	"north" : __DIR__"map_10_24",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
