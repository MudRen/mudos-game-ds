inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("�q�u�Y",({ "mineral collector","collector" }));
        set("long","�ӤH�U�ΨӦ����q�۪��u�H�C\n");
        set("level", 10);
        set("age",35);
        set("chat_chance", 8);
        set("chat_msg", ({
             "�q�u�Y�۵�:�ĨӤZ�q�۽浹�ڴN��F�C\n"
}));
        set("storeroom",__DIR__"obj/mineralroom");
        setup();
}
void init()
{
  add_action("do_sell","sell");
}
