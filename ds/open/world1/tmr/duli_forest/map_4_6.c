inherit ROOM;
void create()
{
	set("short", "�p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_5",
	"south" : __DIR__"map_5_6",
	"east" : __DIR__"map_4_7",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

