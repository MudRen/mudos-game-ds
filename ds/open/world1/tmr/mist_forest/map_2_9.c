inherit ROOM;
void create()
{
	set("short", "�g���˪L-�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_1_9",
	"south" : __DIR__"map_3_9",
	]));
        set("objects",([
                __DIR__"npc/huge-monster":1,
                __DIR__"npc/evil-monster":2,
        ]));

	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

