inherit ROOM;
void create()
{
	set("short", "���~�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_38",
	"south" : __DIR__"map_3_39",
	"north" : __DIR__"map_1_39",
	"east" : __DIR__"map_2_40",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

