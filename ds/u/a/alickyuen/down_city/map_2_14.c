inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_13",
	"east" : __DIR__"map_2_15",
	"south" : __DIR__"map_3_14",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

