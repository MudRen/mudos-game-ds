inherit ROOM;
void create()
{
	set("short", "�۫�");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_11",
	]));
        set("objects", ([
                __DIR__"npc/bandit3" : 1,
                __DIR__"npc/bandit2" : 1,
                __DIR__"npc/bandit" : 2,
        ]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

