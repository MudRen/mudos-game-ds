inherit ROOM;
void create()
{
	set("short", "��O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_7_6",
	"north" : __DIR__"map_5_6",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
