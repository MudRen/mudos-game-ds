inherit ROOM;
void create()
{
	set("short", "�ѹD");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_14_15",
	"south" : __DIR__"map_15_14",
	]));
	set("objects", ([
	__DIR__"../npc/beast_cat_4" : 1,
	]) );
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

