#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIR"小麥草香噴噴內褲面罩-正式版"NOR,({ "sexking head","head" }) );
        set("long",@LONG
這是一件香噴噴的內褲，可以戴在頭上也可穿在褲子裡。
LONG
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("material", "cloth");
                set("unit", "件");
        set("value",0);
        set("volume", 4);
        set("max_lv",50);
        set("limit_lv",1);
      set("armor_prop/str",60);
      set("armor_prop/con",150);
set("armor_prop/armor",5000);;set("armor_prop/show_damage",1);
set("wear_msg","$N從天上召喚一了一個$n掉下來，香噴噴的將$n戴到臉上，一副滿足的樣子∼。。\n");
set("rem_msg", "$N將$n從臉上摘下來，且不忘吸一吸它的香味，ㄣ，好香ㄛ∼。\n");

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

