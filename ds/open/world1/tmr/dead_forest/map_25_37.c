inherit ROOM;
void create()
{
	set("short", "�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_25_36",
	]));
        set("objects",([
                __DIR__"npc/lion2.c" : 2 ,
                __DIR__"npc/lion.c" : 2 ,
        ]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

