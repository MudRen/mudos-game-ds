inherit ROOM;
void create()
{
	set("short", "�l��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_7_37",
	"south" : __DIR__"map_8_36",
	"north" : __DIR__"map_6_36",
    "west" : "/open/world2/lichi_town_1/map_7_35",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
