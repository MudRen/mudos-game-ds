inherit ROOM;
void create()
{
	set("short", "�Ȧ�");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_15_25",
	"south" : __DIR__"map_16_24",
	"west" : __DIR__"map_15_23",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

