inherit ROOM;
void create()
{
	set("short", "���y");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_7_9",
	"south" : __DIR__"map_8_8",
	]));
 set("objects", ([__DIR__"npc/carp" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

