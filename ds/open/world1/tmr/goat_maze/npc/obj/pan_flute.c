#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(HIG"牧神之笛"NOR ,({ "pan flute", "flute" }) );
        set("long",@long
牧神被放逐在神或人的領域之外，祂猶疑徬徨在神或人的邊緣，帶著獸
的貪婪、慾望、情慾、官能的亢奮，喘息著，試圖侵犯褻瀆神或人的領
域。而這是一根牧神所隨身攜帶的短笛，不知道吹奏(blowout)它會發生
什麼事。
long
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "gold");
                set("unit", "根");
                set("value", 0);
        }
        setup();
}

// int query_autoload() { return 1; }

void init()
{
    add_action("do_blowout", "blowout");
}

int do_blowout(string str)
{
    string arg, carg;

    if( this_player()->query_condition("PanFluteCD") )
        return notify_fail("你已經擁有牧神的神力了。\n");

    if( !arg || sscanf(str, "flute %s", arg) != 1) 
        return notify_fail("你想要吹奏什麼？\n");
        switch(arg) {
                case "bar": carg = "獸性";break;
                case "bio": carg = "生物";break;
                case "sou": carg = "心靈";break;
                case "tec": carg = "科技";break;
                case "wit": carg = "魔法";break;
                default:
                        return notify_fail("你只能選擇 bar, bio, wit, sou, 或 tec 一種曲調。\n");
        }
    
    message_vision(
        HIG"$N吹奏起一根短笛，傳出扣人心炫的" + HIW "" + carg + HIG"輕柔旋律，陶醉了所有的人事物。\n"NOR, this_player() );
    message_vision(
        HIY "$N身上發出刺鼻的羊的騷味，似乎有種神聖的力量。\n"NOR, this_player() );
        
        
    this_player()->set_temp("PanFlute", arg);
    this_player()->add_temp("apply/" + arg, 1);
    this_player()->apply_condition("PanFlute", 120);
    this_player()->apply_condition("PanFluteCD", 600);

    return 1;
}

