inherit ROOM;
void create()
{
	set("short", "��������");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_17_8",
	"north" : __DIR__"map_15_8",
	"west" : __DIR__"map_16_7",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
