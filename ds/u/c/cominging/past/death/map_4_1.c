inherit ROOM;
void create()
{
	set("short", "�ۿj�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_2",
	"west" : __DIR__"map_4_0",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
