inherit ROOM;
void create()
{
	set("short", "��q�W���p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_5_5",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/barbarian-captain2":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

