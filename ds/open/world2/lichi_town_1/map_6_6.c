inherit ROOM;
void create()
{
	set("short", "�p�s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_6_7",
	"south" : __DIR__"map_7_6",
	"north" : __DIR__"map_5_6",
	"west" : __DIR__"map_6_5",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

