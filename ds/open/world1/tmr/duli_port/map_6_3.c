inherit ROOM;
void create()
{
	set("short", "������-��D");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_2",
	"east" : __DIR__"map_6_4",
	]));
	set("outdoors","land");
        set("objects",([
                __DIR__"npc/police":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

