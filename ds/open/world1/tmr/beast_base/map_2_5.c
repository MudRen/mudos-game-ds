inherit ROOM;
void create()
{
	set("short", "�-�~���|");
        set("long", @LONG

LONG
);
set("move_direct", "south");

	set("exits",([
	"south" : __DIR__"map_3_5",
	"east" : __DIR__"map_2_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

