inherit ROOM;
void create()
{
	set("short", "�R�x");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_13_25",
	"north" : __DIR__"map_12_24",
	"west" : __DIR__"map_13_23",
	]));
	set("objects",([
	__DIR__"../npc/malo_leolee_17":1,
	__DIR__"../npc/malo_jameschen_16":1,
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

