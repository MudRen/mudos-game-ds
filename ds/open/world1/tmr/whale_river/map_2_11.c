inherit ROOM;
void create()
{
	set("short", "�L�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_3_11",
	"west" : __DIR__"map_2_10",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/toad":2,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

