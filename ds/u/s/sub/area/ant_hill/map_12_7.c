inherit ROOM;
void create()
{
	set("short", "�q�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_13_7",
	"east" : __DIR__"map_12_8",
	]));
        set("objects", ([
        __DIR__"npc/hill_armyant_34" : 2,
        ]) ); 
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

