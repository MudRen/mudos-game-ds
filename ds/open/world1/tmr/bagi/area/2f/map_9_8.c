inherit ROOM;
void create()
{
	set("short", "�۾�");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_9_7",
	"east" : __DIR__"map_9_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

