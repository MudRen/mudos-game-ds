inherit ROOM;
void create()
{
	set("short", "�Z����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_3_14",
	"west" : __DIR__"map_2_13",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

