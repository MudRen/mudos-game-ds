inherit ROOM;
void create()
{
	set("short", "�F�a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_20_1",
	"south" : __DIR__"map_21_2",
	"north" : __DIR__"map_19_2",
	"east" : __DIR__"map_20_3",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

