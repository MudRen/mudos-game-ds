inherit ROOM;
void create()
{
	set("short", "�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_24_36",
	"west" : __DIR__"map_23_35",
	]));
        set("objects",([
                __DIR__"npc/corpse.c" : 4 ,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

