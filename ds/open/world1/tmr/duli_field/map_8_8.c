inherit ROOM;
void create()
{
	set("short", "���ޤJ�f");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_7_8",
	"south" : __DIR__"map_9_8",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

