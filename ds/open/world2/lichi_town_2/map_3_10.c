inherit ROOM;
void create()
{
	set("short", "���U");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_10",
	"north" : __DIR__"map_2_10",
    "west" : "/open/world2/lichi_town_1/map_3_9",
	]));
	set("objects",([
	__DIR__"../npc/malo_ladyyip_12" : 1,
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

