inherit ROOM;
void create()
{
	set("short", "�-�~���|");
        set("long", @LONG

LONG
);
        set("move_direct", "south");
	set("exits",([
	"south" : __DIR__"map_11_10",
	"north" : __DIR__"map_9_10",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

