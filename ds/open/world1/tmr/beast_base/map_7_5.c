inherit ROOM;
void create()
{
	set("short", "�-�~���|");
        set("long", @LONG

LONG
);
set("move_direct", "south");

	set("exits",([
	"south" : __DIR__"map_8_5",
	"north" : __DIR__"map_6_5",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

