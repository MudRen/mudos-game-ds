inherit ITEM;

void create()
{
        set_name("痛心碎骨袋", ({ "heartache crush bone bag", "bag" }));
        set_weight(700);
        set_max_encumbrance(50000);
        if( !clonep() ) {
                set("unit", "隻");
                set("value", 30);
                set("long", "一隻大袋子正面寫著一個「痛」字，而背面寫著「碎」字，看來可以裝不少東西。");
        }
        setup();
}
