inherit ROOM;
void create()
{
	set("short", "�g���˪L-�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_7_2",
	"north" : __DIR__"map_6_1",
	"south" : __DIR__"map_8_1",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

