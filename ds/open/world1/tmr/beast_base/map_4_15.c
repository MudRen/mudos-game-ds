inherit ROOM;
void create()
{
	set("short", "�-�~���|");
        set("long", @LONG

LONG
);
set("move_direct", "south");

	set("exits",([
	"south" : __DIR__"map_5_15",
	"north" : __DIR__"map_3_15",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

