inherit ROOM;
void create()
{
	set("short", "�o�󪺥۸�");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_16_14",
	"north" : __DIR__"map_15_15",
	"east" : __DIR__"map_16_16",
	"south" : __DIR__"map_17_15",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
