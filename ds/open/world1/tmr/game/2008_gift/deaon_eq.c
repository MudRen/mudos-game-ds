#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
   set_name(HIW"天使之翼"NOR,({ "angel wing", "wing" }) );
  set("long",@LONG
    這是一個造型奇特的手套，那不知明的材質和凹凸不平的外表，
更突顯了它的不平凡，在那之上汎著淡淡的銀白色光芒，有著彷彿能
射透一切黑暗的光華，那柔和的光芒在手套的表面淡淡的散發著，好
像隨時都可能熄滅，但無論是在多熾烈的太陽底下一樣還是可以清楚
的看到它的光輝，不過令人奇怪的是，為什麼這手套只有左手的部分
，而沒有右手的部分。
這件裝備為deaon在2008年「鼠來寶」活動中獲得的獎品。
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",1);
    set("unit", "面");
    set("value", 100);
        set("wear_msg",
HIW"      ◢█▇▆▅▄▃▄▅▆◤ "           NOR HIG"當"HIC"$N"HIG"將"HIW"天使之翼"HIG"拿起\n"
HIW"    ◢"HBWHT"◤　◥▇▆▅▄▃▂◢"NOR HIW"◣"NOR HIW" 天使之翼"HIG"的光芒越來越曜眼\n"NOR
HIW"  ◢"HBWHT"◤　◢█▆▅▄▃▂◢"NOR HIW"◣"  NOR HIG"   當你再次看清的時候\n"
HIW"◢"HBWHT"◤　◢◤◥▇▆▄▂█"NOR HIW"◣"    NOR HIC"     $N"HIG"的左手已經化成一片羽翼\n"
HIW"◥██◤　   ◥　　◥"                  NOR HIG"        並散發著和原來一樣淡淡的光輝\n"NOR
);
        set("unequip_msg",HIG"當"HIC"$N"HIG"將"HIW"天使之翼"HIG"放開後，左手的羽翼化為點點光芒散去，回復到原有的樣子。\n"NOR);
  }
  set("armor_prop/armor", 10);
  set("armor_prop/shield", 10);
  set("armor_prop/show_damage",1);
  set("armor_prop/int",2);
  setup();
}

void init() {
        if (!this_object()->query_light() )
                this_object()->start_light(1);
}

int query_autoload() { return 1; }


