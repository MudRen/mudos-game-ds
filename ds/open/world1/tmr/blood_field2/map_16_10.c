inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_16_11",
	"west" : __DIR__"map_16_9",
	"south" : __DIR__"map_17_10",
	"north" : __DIR__"map_15_10",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
