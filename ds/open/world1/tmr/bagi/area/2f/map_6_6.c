inherit ROOM;
void create()
{
	set("short", "�H��}�G�h");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_5",
	"east" : __DIR__"map_6_7",
	"south" : __DIR__"map_7_6",
	"north" : __DIR__"map_5_6",
	]));
        set("objects",([
                __DIR__"npc/madman":1,
        ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

