inherit ROOM;
void create()
{
	set("short", "�Ȧ�");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_16_25",
	"west" : __DIR__"map_17_24",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

