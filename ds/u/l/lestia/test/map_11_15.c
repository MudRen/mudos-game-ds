inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_14",
	"south" : __DIR__"map_12_15",
	"east" : __DIR__"map_11_16",
	"north" : __DIR__"map_10_15",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

