inherit ROOM;
void create()
{
	set("short", "�H��}�G�h");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_12",
	"south" : __DIR__"map_3_13",
	]));
        set("objects",([
                __DIR__"npc/madwoman":1,
        ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

