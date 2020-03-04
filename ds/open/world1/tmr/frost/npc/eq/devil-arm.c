#include <ansi.h>
#include <armor.h>
inherit WRISTS; 
void create()
{
  set_name(HIB"�c�]"NOR"��"RED"��"NOR,({"devil's arm","arm"}));
  set("long", @LONG
LONG);
  set_weight(1800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",0);
    set("material","fur");
  }
  set("limit_lv",35);
  set("limit_mks",3500);
  set("limit_con",45);
  set("limit_dex",37);
  
  set("armor_prop/damage",0);
  set("armor_prop/armor",10);
  set("armor_prop/shield",25); 
  set("armor_prop/dex",2); 
  set("armor_prop/con",2);
  setup();
}

void init()
{
     add_action("do_insert","insert");
}

int do_insert(string arg)
{
    object me = this_player(), ob = this_object(), target;
    string name;
    if( query("equipped") ) return notify_fail("�Х��Ѱ��Ӹ˳ơC\n");
    if( !arg ) return notify_fail("�A�s���n��ƻ��J�c�]���⤺�H\n");  
    target = present(arg, me);
    if( !target ) return notify_fail("�A���W�èS�� " + arg + "�C\n");
    name = target->query("id");
    
    message_vision("$N�w�O��$n��J�c�]���⤺�A�u���@�D���~�{�L�A$n�Q�c�]���⵹�w�ͥͪ��l�F�i�h�C\n", me, target);
    switch( name ){
            case "tian-demon energy":
                 message_vision("�@��"HIG"�H�C��"NOR"������A��¶�b$N�P��A�[�[���ല�h�C\n",ob); 
                 ob->add_temp("devil_energy",1);
            break;
            default:
            break;
            }
    destruct(target);
    if( ob->query_temp("devil_energy") > 199 ) {
        ob->set("name",HIG"�c�]"NOR"��"RED"��"NOR);
        set("armor_prop/damage",0);
        set("armor_prop/armor",15);
        set("armor_prop/shield",35); 
        set("armor_prop/dex",1); 
        set("armor_prop/con",3); 
        set("armor_prop/bio",1);
        set("armor_prop/sou",-1);
    }
    return 1;
}


