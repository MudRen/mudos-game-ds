inherit ROOM;
void create()
{
	set("short", "�F�z");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_1_4",
	"south" : __DIR__"map_2_5",
	]));
	set("outdoors","desert");
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

