inherit ROOM;
void create()
{
	set("short", "�s�a�d�i");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_13_26",
	"north" : __DIR__"map_11_26",
	"west" : __DIR__"map_12_25",
	]));
	set("objects",([
		__DIR__"../npc/malo_barboss_17": 1,
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

