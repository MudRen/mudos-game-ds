inherit ROOM;
void create()
{
	set("short", "���s���]�j�U");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_5_26",
	"south" : __DIR__"map_6_25",
	"north" : __DIR__"map_4_25",
    "west" : "/open/world2/lichi_town_1/map_5_24",
	]));
	set("objects",([
		__DIR__"../npc/basic_master":1,
	]));
	set("no_fight",1);
	set("valid_startroom", 1);
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

