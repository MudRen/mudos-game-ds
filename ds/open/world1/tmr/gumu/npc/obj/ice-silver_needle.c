#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void init()
{
        add_action("do_bawan", "play");
}

void create()
{
        set_name(HIC"冰魄銀針"NOR, ({ "ice-silver needle", "needle" })); 
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這就是武林中人聞之色變的冰魄銀針，針身縷\刻花紋，打造得極是精細，令人忍不住想把玩(play)一番。\n");
                set("value", 3500);
                set("base_unit", "根");
                set("base_weight", 30);
                set("base_value", 0);
                set("meterial", "iron");
                set("wield_msg", "$N小心翼翼地取出一根冰魄銀針當武器。\n");
                set("unwield_msg", "$N把銀針放回衣囊中。\n");
        }
        set_amount(1);
        init_throwing(25);
        setup();
}

int do_bawan()
{
        tell_object(this_player(), "你看著手中的銀針覺得有趣，把針身的花紋細細摸了一遍。\n");
        message_vision(HIB "$N突然覺得手掌麻麻的有些不太靈便，猛然驚覺：「針上有毒，如此把玩，豈不危險？」，\n"
                "忙張開手掌拋下銀針，只見兩手掌心已深黑如墨，手臂麻木感漸漸上升，心中大駭，忍不住便要哭出聲來。\n" NOR, this_player() );
        this_player()->apply_condition("poison", 20);
        this_object()->unequip(); 
        destruct(this_object());
        return 1;
}


