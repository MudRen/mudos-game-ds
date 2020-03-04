inherit ITEM;
inherit F_STUDY;

void create()
{
    set_name("中等國民讀本", "medium education book", "book");
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "本");
        set("value", 200);
        set("long",@long
這是一本屬於中等教育程度的國民所應該研讀的書籍，除了學習其中
待人處事的道理，也包括了更高一等的教育知識。
long
);
        set("required/skill", ([
            "literate" : 30,
        ]));
        set("content", ([
            "literate" : 50
        ]));
    }
    setup();
}

