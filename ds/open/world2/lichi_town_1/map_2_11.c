inherit ROOM;
void create()
{
	set("short", "�ѹD");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_3_11",
	"north" : __DIR__"map_1_11",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

