inherit ROOM;
void create()
{
	set("short", "�a�U�j�X��-�j�U");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_11",
	"north" : __DIR__"map_8_11",
	"east" : __DIR__"map_9_12",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
