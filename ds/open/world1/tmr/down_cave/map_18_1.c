inherit ROOM;
void create()
{
	set("short", "���D");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_17_1",
	"east" : __DIR__"map_18_2",
	]));
        set("objects",([
                __DIR__"npc/guard_monster2":1,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

