inherit ROOM;
void create()
{
	set("short", "�F�z");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_1_7",
	"east" : __DIR__"map_1_9",
	]));
	set("outdoors","desert");
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
