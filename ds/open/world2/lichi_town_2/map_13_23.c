inherit ROOM;
void create()
{
	set("short", "�R�x");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_13_24",
	"north" : __DIR__"map_12_23",
	"west" : __DIR__"map_13_22",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

