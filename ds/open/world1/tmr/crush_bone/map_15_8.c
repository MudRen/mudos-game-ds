inherit ROOM;
void create()
{
	set("short", "�j�U");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_15_9",
	"west" : __DIR__"map_15_7",
	"south" : __DIR__"map_16_8",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

