inherit ROOM;
void create()
{
	set("short", "���D����");
        set("long", @LONG

LONG
);
	set("exits",([
    "east" : "/open/world2/lichi_town_1/map_12_14",
	"south" : __DIR__"map_13_13",
	"north" : __DIR__"map_11_13",
	"west" : __DIR__"map_12_12",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

