inherit ROOM;
void create()
{
	set("short", "�F�z");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_5_1",
	"north" : __DIR__"map_3_1",
	]));
	set("outdoors","desert");
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

