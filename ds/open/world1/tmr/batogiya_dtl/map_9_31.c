inherit ROOM;
void create()
{
	set("short", "�ȩ�");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_9_30",
	]));
       set("no_fight",1);
    set("objects", ([
        __DIR__"npc/lian.c" : 1,
    ]));
          set("valid_startroom", 1);
        setup();
        set("map_long",1);     //show map as long
        load_object("/daemon/board/haha_b");
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

