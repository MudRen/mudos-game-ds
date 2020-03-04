#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIG"樹葉"NOR ,({ "leaf" }) );
  set("long",@LONG 
一片貍貓頭頂上的樹葉，傳聞中貍貓法力的來源就是這片葉子，雖然
它不能提供很好的防護，但是卻能給與強大的法術力量•

LONG
);
  set_weight(10);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",1);
    set("unit", "片");
    set("value",0);
  }
  set("armor_prop/armor",0);
  set("armor_prop/shield",15);
  set("armor_prop/int",3); 
  set("armor_prop/wit",1); 
  set("beast_armor_prop/armor",30);
  setup();
}

