inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_32_3",
	"west" : __DIR__"map_31_2",
	"north" : __DIR__"map_30_3",
	"east" : __DIR__"map_31_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

