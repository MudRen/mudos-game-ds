inherit ROOM;
void create()
{
	set("short", "���D");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_1_9",
	"west" : __DIR__"map_2_8",
	"east" : __DIR__"map_2_10",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

