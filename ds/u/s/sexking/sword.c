#include <weapon.h>
inherit SWORD;
void create()
{
    set_name("小麥芽劍", ({"sexking sword","sword",}) );
     set_weight(5);
     if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "枝");
         set("long",@LONG   這只不過是一枝小麥草的嫩芽罷了。
LONG        );

     set("volume",30);
   set("value", 400);
   set("material","iron");
  set("limit_skill",40);
      }
     set("wield_msg", "$N「哇咧」地一聲抽出一枝$n握在手中。\n");
    set("unwield_msg", "$N將手中的$n摺一摺放入口袋裡。\n");
    init_sword(3000);
     setup();
}
void init()
{
  object me=this_player();
  if(!wizardp(me))
{
  destruct(this_object());
  message_vision("$N要拿的時後小麥芽突然跳了開!\n",me);
  message_vision("到最後已消失無終!\n",me);
} 

}

