inherit ROOM;
void create()
{
	set("short", "���Z�H���p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_9_15",
	"west" : __DIR__"map_10_14",
	"east" : __DIR__"map_10_16",
	"south" : __DIR__"map_11_15",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/barbarian":4,
        ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

