inherit ROOM;
void create()
{
	set("short", "�j�U");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_15_8",
	"south" : __DIR__"map_16_7",
	"north" : __DIR__"map_14_7",
	]));
    set("objects", ([
        __DIR__"npc/orc_herald" : 4,
    ]));

	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
