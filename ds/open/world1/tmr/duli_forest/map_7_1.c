inherit ROOM;
void create()
{
	set("short", "�p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_6_1",
	"south" : __DIR__"map_8_1",
	]));
	set("outdoors","land");
        set("objects",([
                __DIR__"npc/bandit":2,
                  __DIR__"npc/song-fei":1,
        ]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

