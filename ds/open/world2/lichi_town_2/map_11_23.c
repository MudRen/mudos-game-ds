inherit ROOM;
void create()
{
	set("short", "�s�a");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_24",
	"south" : __DIR__"map_12_23",
	"west" : __DIR__"map_11_22",
	]));
	set("objects",([
	__DIR__"../npc/malo_kenny_18":1,
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

