#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name("���w�@��",({"protect amulet","amulet"}) );
  set("long",@LONG
�~�N�[������s�@�šA�n�������@���N�|�H�F�C
LONG);
  set_weight(700); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
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
  message_vision(YEL"\n$N��M�H�����@�a����h\n"NOR,this_object());
  destruct(this_object());
}
