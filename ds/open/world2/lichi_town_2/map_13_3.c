inherit ROOM;
void create()
{
	set("short", "��W");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_14_3",
	"north" : __DIR__"map_12_3",
	"west" : __DIR__"map_13_2",
	]));
	set("outdoors","land");

        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

