inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_5",
	"west" : __DIR__"map_8_3",
	"south" : __DIR__"map_9_4",
	"north" : __DIR__"map_7_4",
	]));
 set("objects", ([__DIR__"npc/tunny" : 2,
	       __DIR__"npc/carp" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

