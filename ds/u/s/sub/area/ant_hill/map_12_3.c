inherit ROOM;
void create()
{
	set("short", "�q�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_12_2",
	"south" : __DIR__"map_13_3",
	]));
        set("objects", ([
        __DIR__"npc/hill_armyant_36" : 2,
        ]) ); 
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

