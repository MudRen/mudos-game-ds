inherit ROOM;
void create()
{
	set("short", "�L���p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_2_10",
	"west" : __DIR__"map_1_9",
	"east" : __DIR__"map_1_11",
	]));
                set("objects", ([ /* sizeof() == 1 */
                          __DIR__"npc/kate" : 1,
                ]));

	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

