inherit ROOM;
void create()
{
    set("short", "��ƫ�");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_1_5",
	"south" : __DIR__"map_2_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
