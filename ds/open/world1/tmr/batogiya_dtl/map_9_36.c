inherit ROOM;
void create()
{
	set("short", "�\��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_36",
	"north" : __DIR__"map_8_36",
	]));
        set("objects",([
                __DIR__"npc/chen-juan" : 1 ,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

