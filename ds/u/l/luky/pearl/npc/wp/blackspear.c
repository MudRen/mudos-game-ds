#include <weapon.h>
inherit FORK;
void create()
{
set_name("黑麟戳",({"dark spear","spear"}));
// 設"mike pen","pen","mike"這樣wield時wield pen or wield mike or wield mike pen就可裝備
set_weight(28000);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("long","\n
這是一把邪惡的鐵戳, 陰寒的妖氣覆蓋了你的全身!\n");
set("unit", "把");
set("spear",75); //社了這個..代表skill 50才能wield且也設定了武器的攻擊力..攻擊力內定是pudon社的...你自己try
set("value",4500);
}
 init_fork(30);
 setup();
}
