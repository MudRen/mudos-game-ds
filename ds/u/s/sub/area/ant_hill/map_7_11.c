inherit ROOM;
void create()
{
	set("short", "�q�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_10",
	"south" : __DIR__"map_8_11",
	]));
        set("objects", ([
        __DIR__"npc/hill_armyant_34" : 2,
        ]) ); 
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

