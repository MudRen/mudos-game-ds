inherit ROOM;
void create()
{
	set("short", "��W");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_3",
	"south" : __DIR__"map_13_2",
	"north" : __DIR__"map_11_2",
	"west" : __DIR__"map_12_1",
    "down": "/open/world2/lichi_town_1/map_12_2",
	]));
	set("outdoors","land");

        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

