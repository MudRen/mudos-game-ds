#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( YEL "黃狗" NOR , ({ "dog" }) );
       set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "隻");
                set("long", "這是一隻看起相當普通的土狗﹐份量大約有十來斤左右。\n");
                set("value", 1000);
                set("material", "steel");
set("wield_msg", "$N抓起$n的後腿，只聽見$n嘶吼的慘叫：「該∼該∼∼」\n");
                set("unwield_msg", "$N將手中的$n放在地上。\n");
        }
    init_sword(5000);
set("combat_msg",({
"$N抓起$w的後腳，往$n的$l揮揮去，一招" HIB "「瘋狗發威」" NOR "往$n的$l狂咬。\n",
"$N抓起$w的頭,只聽見$w嘶啞的慘叫，使出一招" HIY "「野狗撒尿」" NOR "，\n"+
     "接著眼前有" HIY "黃色液體" NOR "往$n的$l噴去。\n",
"$N對著$w吹了吹口哨，使出一招" HIG "「狗咬呂洞賓」" NOR "只見$w衝向$n往$l咬去。\n",
}) ); 
        setup();
}
