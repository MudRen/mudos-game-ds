inherit ROOM;
void create()
{
	set("short", "�˪L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_12",
	]));
	set("outdoors","forest");
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

