inherit ROOM;
void create()
{
	set("short", "���D");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_11_1",
	"east" : __DIR__"map_12_2",
	"south" : __DIR__"map_13_1",
	]));
        set("objects",([
		__DIR__"npc/slovakia" : 1,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
