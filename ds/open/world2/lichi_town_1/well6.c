inherit ROOM;

void create()
{
	set("short", "�����K�D");
        set("long", @LONG
�o�Ӥ����G���F�ܤ[�A�������F�\�h����������C
LONG
);
	set("exits",([
		"east" : __DIR__"well5",
		"west" : __DIR__"well7",
		"north" : __DIR__"well8",
		"south" : __DIR__"well9",
	]));

    set("objects", ([
       // __DIR__"../npc/beast_frog_3" : 1,
    ]));
        setup();
}
