inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_2",
	"south" : __DIR__"map_8_3",
	"north" : __DIR__"map_6_3",
	"east" : __DIR__"map_7_4",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

