inherit ROOM;
void create()
{
	set("short", "���s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_34",
	"north" : __DIR__"map_8_34",
	"west" : __DIR__"map_9_33",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

