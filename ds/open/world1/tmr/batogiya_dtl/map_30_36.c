inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_31_36",
	"west" : __DIR__"map_30_35",
	"north" : __DIR__"map_29_36",
	"east" : __DIR__"map_30_37",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

