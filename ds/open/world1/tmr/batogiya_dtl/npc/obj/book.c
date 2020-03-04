inherit ITEM;
inherit F_STUDY;

void create()
{
    set_name("哈哈村通史", "haha book", "book");
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "本");
        set("value", 5000);
        set("long",@long
是運用文言文寫成的書藉，是哈顫的阿公「哈橫」所撰著，記錄著哈
哈村數百年之間的歷史，是一部不錯的典藉，但必需有相當足夠的語
文造詣才能讀得通。
long
);
        set("required/skill", ([
            "literate" : 110,
        ]));
        set("content", ([
            "literate" : 130
        ]));
    }
    setup();
}

