inherit ROOM;
void create()
{
	set("short", "�����۸�");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_2_5",
	"north" : __DIR__"map_0_5",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

