inherit ROOM;
void create()
{
	set("short", "��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_15_12",
	"north" : __DIR__"map_14_11",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

