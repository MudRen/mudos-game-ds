inherit ROOM;
void create()
{
	set("short", "�F�a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_31_4",
	"south" : __DIR__"map_32_5",
	"north" : __DIR__"map_30_5",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

