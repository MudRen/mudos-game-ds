inherit ROOM;
void create()
{
	set("short", "�p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_15_4",
	"south" : __DIR__"map_17_4",
	]));
	set("outdoors","land");
        set("objects",([
                __DIR__"npc/bandit":2,
        ]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

