inherit ROOM;
void create()
{
	set("short", "�p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_9",
	"west" : __DIR__"map_4_8",
	"south" : __DIR__"map_5_9",
	"east" : __DIR__"map_4_10",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

