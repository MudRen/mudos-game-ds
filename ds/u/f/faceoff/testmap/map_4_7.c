inherit ROOM;
void create()
{
	set("short", "�L��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_6",
	]));
set("objects", ([__DIR__"npc/tunny" : 1,
	     __DIR__"npc/fish" : 1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

