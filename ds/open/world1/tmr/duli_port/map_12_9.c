inherit ROOM;
void create()
{
	set("short", "�����s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_11_9",
	"east" : __DIR__"map_12_10",
	]));
	set("outdoors","land");
        set("objects",([
                __DIR__"npc/fighter":2,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

