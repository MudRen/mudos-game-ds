inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_25_14",
	"north" : __DIR__"map_24_15",
	"east" : __DIR__"map_25_16",
    "enter" : "/open/world2/lichi_town_1/map_0_19",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

