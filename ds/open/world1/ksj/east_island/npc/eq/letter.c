#include <path.h>
inherit ITEM;

void create()
{
  set_name("信", ({"hoshiakari's letter","letter"}) );
  set("long",@long
一封柳生．星明寫給日向．朝霞的信。

    朝霞，１０前我率領弟子及村中勇士前往櫻花林中討伐天狗，卻
    意外發現多年前被天狗擄走的日向．霧子，當時由於群情激憤，
    導致誤會而與你的父親秋川．旭發生衝突，而此時天狗又率眾來
    襲，混亂中導致妳的母親霧子不幸身亡，而我們一行人則帶著妳
    敗逃回村中，冷靜下來後我才發現其中的誤會，而我也深感愧疚
    ，如今妳已長大了，因此將事情的因果告訴妳，妳的父親就住在
    櫻花林外的小竹林中，捎信給妳的俠客武藝高強，妳可與之同行
    前往。                                        柳生．星明

long);
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "封");
    set("volume",1);
    set("no_sell",1);
  }
  setup(); 
}
