inherit ROOM;
void create()
{
	set("short", "���Z�H���p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_8_4",
	"east" : __DIR__"map_9_5",
	"south" : __DIR__"map_10_4",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/woman-barbarian":2,
                __DIR__"npc/barbarian":2,
        ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

