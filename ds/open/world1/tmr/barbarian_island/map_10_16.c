inherit ROOM;
void create()
{
	set("short", "���Z�H���p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_9_16",
	"west" : __DIR__"map_10_15",
	"east" : __DIR__"map_10_17",
	"south" : __DIR__"map_11_16",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/barbarian":2,
                __DIR__"npc/barbarian-captain":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

