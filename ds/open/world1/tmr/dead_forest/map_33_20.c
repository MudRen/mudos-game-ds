inherit ROOM;
void create()
{
	set("short", "�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_34_20",
	"west" : __DIR__"map_33_19",
	"north" : __DIR__"map_32_20",
	]));
        set("objects" , ([
                __DIR__"npc/wildman-captain.c" : 1 ,
                __DIR__"npc/wildman.c" : 2 ,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

