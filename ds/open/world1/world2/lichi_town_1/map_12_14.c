inherit ROOM;
void create()
{
	set("short", "�ө��J�f");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_15",
    "west" : "/open/world2/lichi_town_2/map_12_13",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

