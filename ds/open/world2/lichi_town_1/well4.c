inherit ROOM;

void create()
{
	set("short", "�����K�D");
        set("long", @LONG
�o�Ӥ����G���F�ܤ[�A�������F�\�h����������C
LONG
);
	set("exits",([
		"south" : __DIR__"well3",
		"west" : __DIR__"well5",
	]));

    set("objects", ([
       // __DIR__"../npc/beast_frog_3" : 1,
    ]));
        setup();
}
