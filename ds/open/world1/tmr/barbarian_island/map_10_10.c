inherit ROOM;
void create()
{
	set("short", "��q�W���p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_10_9",
	"east" : __DIR__"map_10_11",
	"south" : __DIR__"map_11_10",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/barbarian":2,
        ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

