inherit ROOM;
void create()
{
	set("short", "�����۸�");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_3_6",
	"east" : __DIR__"map_3_8",
	"south" : __DIR__"map_4_7",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

