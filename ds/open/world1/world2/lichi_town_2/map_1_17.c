inherit ROOM;
void create()
{
	set("short", "ĵ�ë�");
        set("long", @LONG

LONG
);
	set("exits",([
    "east" : "/open/world2/lichi_town_1/map_1_18",
	"south" : __DIR__"map_2_17",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

