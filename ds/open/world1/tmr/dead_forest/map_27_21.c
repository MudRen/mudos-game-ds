inherit ROOM;
void create()
{
	set("short", "�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_28_21",
	"north" : __DIR__"map_26_21",
        ]) );
        set("objects", ([
                 __DIR__"npc/wildman_captain2.c" : 1 ,
                __DIR__"npc/wildman.c" : 3
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

