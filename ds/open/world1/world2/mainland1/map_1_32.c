inherit ROOM;
void create()
{
	set("short", "�˪L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_1_31",
	"south" : __DIR__"map_2_32",
	"north" : __DIR__"map_0_32",
	"east" : __DIR__"map_1_33",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

