inherit ROOM;
void create()
{
	set("short", "�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_23_6",
	"north" : __DIR__"map_22_7",
	]));
        set("objects",([
                __DIR__"npc/corpse.c" : 2 ,
                __DIR__"npc/corpse2.c" : 2 ,
        ]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

