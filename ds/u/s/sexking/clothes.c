#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("小麥草西裝",({"sexking clothes","clothes"}) );
        set("long",@LONG
   這是一件標有小麥草標誌的衣服，是時下最流行的款式。
LONG);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("armor_prop/armor",201);
        setup();
        set("value",100000);
        set("volume", 4);
        set("armor_prop/int",75);
        set("armor_prop/dex",90);
        set("armor_prop/con",10);
}
int query_autoload() { return 1; } 
void init()
{
  object me=this_player();
  if(!wizardp(me))
{
  destruct(this_object());
  message_vision("$N要拿起時西裝突然爆炸了!\n",me);
  message_vision("$N嚇的冷汗直流!\n",me);
} 

}

