inherit ROOM;
void create()
{
	set("short", "�Ȧ�");
        set("long", @LONG

LONG
);
	set("exits",([
    "east" : "/open/world2/lichi_town_1/map_16_26",
	"south" : __DIR__"map_17_25",
	"north" : __DIR__"map_15_25",
	"west" : __DIR__"map_16_24",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

