inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_15",
	"west" : __DIR__"map_9_13",
	"south" : __DIR__"map_10_14",
	"north" : __DIR__"map_8_14",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
