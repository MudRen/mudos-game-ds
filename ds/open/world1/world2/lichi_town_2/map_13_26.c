inherit ROOM;
void create()
{
	set("short", "�s�a�p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_12_26",
	"west" : __DIR__"map_13_25",
	]));
	set("light",1);
	set("objects",([
		__DIR__"../npc/malo_barcook_21":1,
	]));
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

