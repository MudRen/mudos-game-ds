inherit ROOM;
void create()
{
	set("short", "�s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_10_24",
	"east" : __DIR__"map_11_25",
	]));
    set("objects", ([
        __DIR__"npc/stake" : 3,
    ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

