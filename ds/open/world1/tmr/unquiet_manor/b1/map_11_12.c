inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_12_12",
	"north" : __DIR__"map_10_12",
	"west" : __DIR__"map_11_11",
	"east" : __DIR__"map_11_13",
	]));
        set("objects", ([
                "/open/world1/tmr/unquiet_manor/npc/insect" : 2
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

