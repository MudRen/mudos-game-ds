inherit ROOM;
void create()
{
	set("short", "�۾�");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_22_19",
	"east" : __DIR__"map_22_21",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

