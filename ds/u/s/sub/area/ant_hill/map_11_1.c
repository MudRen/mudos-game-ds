inherit ROOM;
void create()
{
	set("short", "�q�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_12_1",
	"north" : __DIR__"map_10_1",
	]));
        set("objects", ([
        __DIR__"npc/hill_armyant_36" : 2,
        ]) ); 
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
