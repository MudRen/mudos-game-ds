inherit ROOM;
void create()
{
	set("short", "�˪L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_34",
	"south" : __DIR__"map_3_35",
	"north" : __DIR__"map_1_35",
	"east" : __DIR__"map_2_36",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

