inherit ROOM;
void create()
{
	set("short", "�Ы�");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_7",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/woman":1,
                  __DIR__"npc/teacher":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

