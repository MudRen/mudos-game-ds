inherit ROOM;
void create()
{
	set("short", "�g���˪L-�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_16_9",
	"east" : __DIR__"map_16_11",
	"north" : __DIR__"map_15_10",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

