inherit ROOM;
void create()
{
	set("short", "���~�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_22_32",
	"south" : __DIR__"map_23_33",
	"north" : __DIR__"map_21_33",
	"east" : __DIR__"map_22_34",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

