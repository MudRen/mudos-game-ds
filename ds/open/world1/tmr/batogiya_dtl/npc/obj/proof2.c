inherit ITEM;

void create()
{
    set_name("哈哈村選舉不公證據其二", ({ "haha 2 proof", "proof", "_HAHA_PROOF_2_" }));
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "本");
        set("value", 0);
        set("long",@long
一本由「宋神掌」處心積慮運用「無限上綱」手法的高明證據，
或許可以讓「哈顫」能平反的證據。
long
);
    }
    setup();
}

