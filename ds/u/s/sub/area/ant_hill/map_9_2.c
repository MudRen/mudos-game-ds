inherit ROOM;
void create()
{
	set("short", "�q�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_9_1",
	"north" : __DIR__"map_8_2",
	]));
        set("objects", ([
        __DIR__"npc/hill_armyant_36" : 2,
        ]) ); 
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

