inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_17_16",
	"north" : __DIR__"map_16_17",
	"east" : __DIR__"map_17_18",
	"south" : __DIR__"map_18_17",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
