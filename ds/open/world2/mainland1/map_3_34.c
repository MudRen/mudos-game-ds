inherit ROOM;
void create()
{
	set("short", "�˪L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_3_33",
	"south" : __DIR__"map_4_34",
	"north" : __DIR__"map_2_34",
	"east" : __DIR__"map_3_35",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

