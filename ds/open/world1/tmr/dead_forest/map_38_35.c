inherit ROOM;
void create()
{
	set("short", "�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_37_35",
	]));
        set("objects" , ([
                __DIR__"npc/lion.c" : 2 ,
                 __DIR__"npc/lion3.c" : 1 ,
        ]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

