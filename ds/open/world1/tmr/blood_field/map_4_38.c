inherit ROOM;
void create()
{
	set("short", "���s��}");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_38",
	"west" : __DIR__"map_4_37",
	"south" : __DIR__"map_5_38",
	"east" : __DIR__"map_4_39",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

