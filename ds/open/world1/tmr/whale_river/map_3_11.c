inherit ROOM;
void create()
{
	set("short", "�L�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_11",
	"north" : __DIR__"map_2_11",
	"east" : __DIR__"map_3_12",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

