#include <weapon.h>
inherit HAMMER;
void create()
{
set_name("黑麟戰鎚",({"dark hammer","hammer"}));
// 設"mike pen","pen","mike"這樣wield時wield pen or wield mike or wield mike pen就可裝備
set_weight(40000);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("long","\n
一把沉重的戰鎚, 外面還包了一層閃亮的黑色鱗片\n");
set("unit", "把");
set("hammer",160);//skill 160玩家要skill 160才能使用by pudon
set("value",6300);
 }
 setup();
}
