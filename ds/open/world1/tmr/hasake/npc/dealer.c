inherit NPC;
inherit SHOPMAN;

void create()
{
        set_name("�i���ͷN�H", ({ "persian seller", "seller" }));
        set("gender", "�k��");
        set("age", 40 + random(10));
        set("long", "�@�Ӻ�����i���ͷN�H�C�����Ų���, �ݵۧA�y�W�S�X���B�����e�C\n");
        set("attitude", "friendly");
        setup();
        set("no_kill", 1);
        set("chat_chance", 5);
        set("chat_msg", ({
"�i���ͷN�H��A���B�a���F�@�U�����C\n",
        }));
        set("storeroom",__DIR__"shop_room");
        carry_object(__DIR__"obj/wandao")->wield();
        setup();
}


void init()
{
  add_action("do_buy","buy");
  add_action("do_sell","sell");
  add_action("do_list","list");
}

