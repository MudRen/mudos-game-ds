inherit ROOM;
void create()
{
	set("short", "�L��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_3_9",
	"east" : __DIR__"map_3_11",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
