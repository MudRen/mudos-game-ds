inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_5",
	"west" : __DIR__"map_4_3",
	"south" : __DIR__"map_5_4",
	"north" : __DIR__"map_3_4",
	]));
 set("objects", ([__DIR__"../npc/tunny" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

