inherit ROOM;
void create()
{
	set("short", "�L�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_5_7",
	"north" : __DIR__"map_4_8",
	"east" : __DIR__"map_5_9",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/toad":2,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

