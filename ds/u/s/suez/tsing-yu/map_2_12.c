inherit ROOM;
void create()
{
	set("short", "��D");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_3_12",
	"north" : __DIR__"map_1_12",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

