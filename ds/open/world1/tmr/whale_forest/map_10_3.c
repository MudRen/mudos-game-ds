inherit ROOM;
void create()
{
	set("short", "�L���p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_3",
	"east" : __DIR__"map_10_4",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/forest-garrison":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

