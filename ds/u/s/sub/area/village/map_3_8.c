inherit ROOM;
void create()
{
	set("short", "�H�۸�");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_8",
	"north" : __DIR__"map_2_8",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
