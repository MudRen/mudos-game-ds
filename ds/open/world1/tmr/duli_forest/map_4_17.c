inherit ROOM;
void create()
{
	set("short", "�p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_17",
	"west" : __DIR__"map_4_16",
	"south" : __DIR__"map_5_17",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

