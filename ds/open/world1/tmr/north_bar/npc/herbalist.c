inherit NPC;
inherit SELLMAN;

string gflower(object me);

void create()
{
        set_name("���E�ѪO",({ "herbalist" }));
        set("long","�o�O�@�Ӹg���ľQ�Q�X�~���ľQ�ѪO�C"
        );
        set("age",50+random(10));
        set("no_fight",1);
        set("chat_chance", 3);
        set("chat_msg", ({
		  (: command,"say �̪񦳤��֥~�a�ȡA�ͷN�ˬO�n�F���֡C" :),
		  (: command,"smile" :),
	}) );
        set("sell_list",([
                __DIR__"obj/appill.c": 20,
                __DIR__"obj/breath-pill.c": 20,
		]));
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}
