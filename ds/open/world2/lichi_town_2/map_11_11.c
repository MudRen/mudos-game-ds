inherit ROOM;
void create()
{
	set("short", "���D����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_12",
	"south" : __DIR__"map_12_11",
	"north" : __DIR__"map_10_11",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

