inherit ROOM;
void create()
{
	set("short", "�s�a�d�i");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_12_26",
	"west" : __DIR__"map_11_25",
	]));
	set("objects",([
		__DIR__"../npc/malo_barlady_17": 1,
		__DIR__"../npc/malo_haoming_12": 1,
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

