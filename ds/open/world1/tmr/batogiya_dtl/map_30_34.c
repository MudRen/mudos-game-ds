inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_31_34",
	"west" : __DIR__"map_30_33",
	"north" : __DIR__"map_29_34",
	"east" : __DIR__"map_30_35",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

