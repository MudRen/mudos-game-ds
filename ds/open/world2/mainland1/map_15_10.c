inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_15_9",
	"south" : __DIR__"map_16_10",
	"north" : __DIR__"map_14_10",
	"east" : __DIR__"map_15_11",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
