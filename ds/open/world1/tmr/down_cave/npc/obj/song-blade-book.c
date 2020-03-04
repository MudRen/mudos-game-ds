inherit ITEM;
inherit F_STUDY;

void create()
{
    set_name("宋家刀譜", "song blade book", "book");
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "本");
        set("value", 0);
         set("no_give",1);
        set("long",@long
　　這是一本刀譜，只有薄薄不到十頁的泛黃牛皮紙，每頁上都刻畫著刀
招及寥寥數字像詩又像詞的招式解說，封面上赫然四個大字「宋家刀法」。
long
);
        set("required/skill", ([
            "literate" : 50,
        ]));
        set("content", ([
            "song blade" : 20,
        ]));
    }
    setup();
}

