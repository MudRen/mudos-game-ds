#include <path.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("�ӤH", ({ "shop man", "man", "shop" }) );
        set("long",
                "�L�O�ӯ�������ӤH�A�`�a�@�ǩ_�S�����C\n"
                "�A�i�H�ݰݥL���椰��F��(list),�άO�V�L�ʶR�U�ت��~(buy)\n"
                ",�άO�V�L�X��F��(sell)\n"
        );
        set("level", 10);
        set("no_fight",1);
        set("age", 35);
        set("storeroom", __DIR__"shop/shop1");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
        add_action("do_sell","sell");
}

