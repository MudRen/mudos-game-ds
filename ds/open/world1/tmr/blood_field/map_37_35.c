inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_36_35",
	"west" : __DIR__"map_37_34",
	"south" : __DIR__"map_38_35",
	"east" : __DIR__"map_37_36",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

