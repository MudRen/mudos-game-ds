inherit ROOM;
void create()
{
	set("short", "���Z�H���p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_15_5",
	"east" : __DIR__"map_16_6",
	]));
        set("objects",([
                __DIR__"npc/barbarian_village_head":1,
        ]));

	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

