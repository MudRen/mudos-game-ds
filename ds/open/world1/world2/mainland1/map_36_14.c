inherit ROOM;
void create()
{
	set("short", "�F�a");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_37_14",
	"north" : __DIR__"map_35_14",
	"east" : __DIR__"map_36_15",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

