inherit ROOM;
void create()
{
	set("short", "�Цa");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_11_12",
	"west" : __DIR__"map_12_11",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
