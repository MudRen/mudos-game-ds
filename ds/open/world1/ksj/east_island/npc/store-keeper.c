#include <path.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("���ê�", ({"store keeper","keeper"}));
        set("long",
                "�@��G�G�D�D���ӤH�A��l�W���F�@���ʭ�������A��W���۪��Ϥ�\n"
                "�A���ɦa�l�۷Ϩ�������������~�C\n");
        set("level", 20);
        set("no_fight",1);
        set("age", 43);
        set("storeroom", __DIR__"shop.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
        add_action("do_sell","sell");
}
