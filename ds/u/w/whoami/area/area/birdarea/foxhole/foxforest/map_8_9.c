inherit ROOM;
void create()
{
	set("short", "�L�y");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_10",
	"south" : __DIR__"map_9_9",
	"north" : __DIR__"map_7_9",
	]));
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

