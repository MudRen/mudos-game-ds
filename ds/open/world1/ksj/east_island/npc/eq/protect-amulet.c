#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name("平安護符",({"protect amulet","amulet"}) );
  set("long",@LONG
年代久遠的木製護符，好像輕輕一捏就會碎了。
LONG);
  set_weight(700); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "個");
    set("value",0);          
    set("volume", 1);                       
    set("material", "stone");
  }
  set("armor_prop/armor",1);       
  setup();
  call_out("dest_amulet", 90);
}

void dest_amulet()
{
  message_vision(YEL"\n$N突然碎裂成一地的木屑\n"NOR,this_object());
  destruct(this_object());
}
