inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_18_26",
	"west" : __DIR__"map_17_25",
	"north" : __DIR__"map_16_26",
	"east" : __DIR__"map_17_27",
	]));
    set("objects", ([
        __DIR__"npc/villager.c" : 3,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

