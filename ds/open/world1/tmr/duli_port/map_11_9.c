inherit ROOM;
void create()
{
	set("short", "�����s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_12_9",
	"north" : __DIR__"map_10_9",
	"east" : __DIR__"map_11_10",
	]));
        set("objects",([
                __DIR__"npc/fighter":2,
        ]));

	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

