inherit ROOM;
void create()
{
	set("short", "�D�㩱");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_19",
	"south" : __DIR__"map_13_18",
    "north" : "/open/world2/lichi_town_1/map_11_18",
	"west" : __DIR__"map_12_17",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

