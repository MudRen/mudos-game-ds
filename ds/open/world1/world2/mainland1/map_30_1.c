inherit ROOM;
void create()
{
	set("short", "�F�a");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_31_1",
	"north" : __DIR__"map_29_1",
	"east" : __DIR__"map_30_2",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

