inherit ROOM;
void create()
{
	set("short", "�ۿj�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_15",
	"north" : __DIR__"map_3_16",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

