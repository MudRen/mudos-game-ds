inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_18_8",
	"north" : __DIR__"map_17_9",
	"east" : __DIR__"map_18_10",
	"south" : __DIR__"map_19_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
