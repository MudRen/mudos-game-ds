inherit ROOM;
void create()
{
	set("short", "�۫�");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_15",
	]));
        set("objects", ([
                __DIR__"npc/bandit3" : 2,
                __DIR__"npc/bandit2" : 2,
        ]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

