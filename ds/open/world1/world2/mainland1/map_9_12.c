inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_9_11",
	"south" : __DIR__"map_10_12",
	"north" : __DIR__"map_8_12",
	"east" : __DIR__"map_9_13",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

