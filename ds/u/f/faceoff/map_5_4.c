inherit ROOM;
void create()
{
	set("short", "�L��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_5_5",
	"north" : __DIR__"map_4_4",
	]));
	 set("objects", ([__DIR__"area/npc/fish" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

