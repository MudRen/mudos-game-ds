inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_15",
	"north" : __DIR__"map_7_14",
	"south" : __DIR__"map_9_14",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

