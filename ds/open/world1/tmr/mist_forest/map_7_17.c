inherit ROOM;
void create()
{
	set("short", "�g���˪L-�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_16",
	"north" : __DIR__"map_6_17",
	"south" : __DIR__"map_8_17",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

