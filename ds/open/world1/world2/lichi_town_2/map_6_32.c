inherit MOBROOM;
void create()
{
	set("short", "�ܮw");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_6_33",
	"north" : __DIR__"map_5_32",
	"west" : __DIR__"map_6_31",
	]));
	set("objects", ([
	__DIR__"../npc/beast_spider_5" : 2,
	]) );
	set("chance",33);	
	set("mob_amount",4);	
	set("mob_object",({	
	__DIR__"../npc/beast_mosquito_1",
	__DIR__"../npc/beast_spider_8",
	__DIR__"../npc/beast_rat_3",
	__DIR__"../npc/beast_spider_5",
	}) );
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

