// 27/12
inherit SELLMAN;
inherit NPC;
void create()
{
	set_name("���P��", ({"seller"}) );
	set("long", "�b�ʪ����¾�����P���A���b�V�O���P�@�ǰʪ��骺�S���C\n");
	set("race", "�H��");
	set("age", 40);
	set("level", 5);
        set("sell_list",([
__DIR__"obj/food" : 10,
        ]) );
	setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
