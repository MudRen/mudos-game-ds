#include <armor.h>
#include <ansi2.h>
inherit CLOTH;

void create()
{
  set_name(HBK"�¦���T"NOR ,({ "black-magic robe","robe" }) );
  set("long",@LONG
�@��¦⪺���T�A�~���ǯ}��A�O���]�k�s�y�����u��´�����A�O
�k�v�N�h�ҷR�Ϊ��˳ơA���������]�k���m�O�C
LONG
);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",3000);
    set("material", "fur");
    set("limit_lv",25);
  } 
    set("armor_prop/shield",13);
    set("armor_prop/str",-1);
    set("armor_prop/int",3);
    set("armor_prop/armor",4);
    set("beast_armor_prop/armor",20);
    set("beast_armor_prop/shield",20);
    set("beast_armor_prop/wit",1);
  setup();
}

