#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
              set_name(HIW"光影刀"NOR,({"light blade","blade"}));
              set("long","一把西贏的光影刀，會發出銀白色光影.\n");
              set_weight(3000);
              if( clonep() )
                      set_default_object(__FILE__);
              else {
                    set("unit", "把");
                    set("value",1000);
                    set("material","iron");
                 }
                 init_blade(10);
set("combat_msg", ({    //攻擊訊息 $N是自己 $n是對方 $l 是對方受攻部位 $w是武器�
                "$N手握$w，只見銀白色影光一閃，便朝$n的頭部一砍\n",
                "$N把$w往$n的肚子狠狠地一捅，頓時$n血流大注，噴到$N臉上\n",
                "$N用$w往$n的腳跟部刺去，結果$n痛的哇哇大叫\n",
                "$N將$w一反拿，便向$n的手部橫砍\n",
                "$N大叫：「喝!殺!」，把$n由上往下一大砍\n",
                "$N把$w往$n的肚子狠狠地一捅，頓時$n血流大注，噴到$N臉上\n",
                "$N用$w往$n的腳跟部刺去，結果$n痛的哇哇大叫\n",
                "$N將$w一反拿，便向$n的手部橫砍\n",
                "$N大叫：「喝!殺!」，把$n由上往下一大砍\n",
    }) );
           setup();
}

