inherit ROOM;
void create()
{
	set("short", "��D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_1_14",
	"east" : __DIR__"map_1_16",
	]));
	set("light",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

