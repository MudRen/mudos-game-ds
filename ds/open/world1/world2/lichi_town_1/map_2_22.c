inherit ROOM;
void create()
{
	set("short", "�A���");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_3_22",
    "north" : "/open/world2/lichi_town_2/map_1_22",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

