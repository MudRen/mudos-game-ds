#include <ansi.h>

#include <weapon.h>

inherit BLADE;

void create()

{

set_name(HIR"傲世狂人" NOR ,({"crazy of blade","blade"}));

set("long","這是羽夜子所配帶的武器。\n");

set_weight(10000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

set("unit", "把");

set("value",5000);

set("volume",3);

set("limit_str",10);

set("limit_con",10);

        }

set("wield_msg",HIB"$N抽出一把$n"HIB",頓時間空氣突然凝結。\n");

set("unwield_msg", HIB"$N放下手中的$n"HIB", 空氣終於恢復原有的寧靜。\n");



set("combat_msg", ({

   HIR"$N使出"HIB"羽夜四刀"HIW"之"HIY"「"HIW"羽破天驚"HIY"」"HIR"，分別刺入你的胸口和腹部。\n\n"NOR,



   HIR"$N使出"HIB"羽夜四刀"HIW"之"HIY"「"BLK"黑夜無盡"HIY"」"HIR"，朦朦的黑氣便穿入$n"HIR"的體內。\n\n"NOR,

   HIR"$N使出"HIB"羽夜四刀"HIW"之"HIY"「"HIG"天外飛仙"HIY"」"HIR"，快速的刀氣穿入了$n"HIR"，只見$n"HIR"疼痛地戰不起來。\n\n"NOR,







   HIR"$N使出"HIB"羽夜四刀"HIW"之"HIY"「"NOR""MAG"羽夜"HIY"」"HIR"，刀突然離開主人的手上向$n"HIR"猛攻，只見$n"HIR"疼痛無邊，不能自我。\n\n"NOR,



}) );

init_blade(69);

setup();

}
