inherit ROOM;
void create()
{
	set("short", "�F�a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_33_1",
	"north" : __DIR__"map_32_2",
	"east" : __DIR__"map_33_3",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

