inherit ROOM;
void create()
{
	set("short", "�q�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_12",
	"south" : __DIR__"map_5_13",
	"east" : __DIR__"map_4_14",
	]));
        set("objects", ([
        __DIR__"npc/hill_armyant_34" : 1,
        __DIR__"npc/hill_worker_20" : 2,        
        ]) ); 
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

