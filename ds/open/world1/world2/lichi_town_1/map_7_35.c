inherit ROOM;
void create()
{
	set("short", "�l���j��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_34",
    "east" : "/open/world2/lichi_town_2/map_7_36",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

