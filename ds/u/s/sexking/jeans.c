#include <armor.h>
inherit PANTS;

void create()
{
        set_name("麥草小內褲",({ "sexking jeans","jeans" }) );
        set("long",@LONG
這是一件很漂亮的內褲,在屁股的部份還有幾根雜草。
LONG
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("material", "cloth");
                set("unit", "件");
        set("value",100000);
        set("volume", 4);
        set("max_lv",50);
        set("limit_lv",1);
      set("armor_prop/str",60);
      set("armor_prop/con",150);
set("armor_prop/armor",5000);;set("armor_prop/show_damage",1);
  }
      setup();
}
int query_autoload() { return 1; }
void init()
{
  object me=this_player();
  if(!wizardp(me))
{
  destruct(this_object());
  message_vision("$N要拿起時內褲突然融化了!\n",me);
  message_vision("到最後已消失無終!\n",me);
} 

}

