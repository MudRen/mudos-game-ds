inherit ROOM;
void create()
{
	set("short", "�s�u�s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_21",
	"south" : __DIR__"map_11_20",
	"north" : __DIR__"map_9_20",
	"west" : __DIR__"map_10_19",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

