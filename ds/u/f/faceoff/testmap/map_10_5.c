inherit ROOM;
void create()
{
	set("short", "�L��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_6",
	"west" : __DIR__"map_10_4",
	]));
set("objects", ([__DIR__"npc/tunny" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

