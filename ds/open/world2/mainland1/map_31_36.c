inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_31_35",
	"north" : __DIR__"map_30_36",
	"east" : __DIR__"map_31_37",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

