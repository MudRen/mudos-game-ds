inherit ROOM;
void create()
{
	set("short", "�s�a");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_25",
	"south" : __DIR__"map_12_24",
    "north" : "/open/world2/lichi_town_1/map_10_24",
	"west" : __DIR__"map_11_23",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

