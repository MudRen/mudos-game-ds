inherit ROOM;
void create()
{
	set("short", "�A���");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_1_23",
        "south" : "/open/world2/lichi_town_1/map_2_22",
	"west" : __DIR__"map_1_21",
	]));
	set("objects",([
	__DIR__"../npc/malo_towerguard_19":1,
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

