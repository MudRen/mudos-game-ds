inherit ROOM;
void create()
{
	set("short", "�L����a");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_15_13",
	]));
	set("outdoors","forest");
                set("objects", ([ /* sizeof() == 1 */
                          __DIR__"npc/horse" : 4,
                ]));


        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

