#include <ansi2.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(HIM"�[������"NOR ,({ "observe necklace","necklace" }) );
  set("long",@LONG
�^�O�_�S���۪�����A�Ѧ�j����������s���A�i�ϥΨӤF�Ѫ��~��
�@�ǯS��(showing)�C
LONG);
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("male_only",1);
    set("material", "stone");
    set("volume",1);
    set("unit", "��");
    set("value",1500);
  }
  set("armor_prop/armor",1);
  set("armor_prop/int",1);
  setup();
}

void init()
{
  add_action("do_showing","showing");
}

int do_showing(string arg)
{
  object obj,me;
  string limit="",other="";
  int i;  
  me = this_player();
  if(!arg) return notify_fail("�A�n�[�ݤ��򪫫~����O�ȡH\n");
  if( me->query_temp("armor/neck")!=this_object() ) return notify_fail("�A���������W����C\n");
  if(!objectp(obj = present(arg, me)) )
  {
    if(objectp(obj = present(arg, environment(me))) && !obj->is_character())
      tell_room(environment(me), me->name() + "�n�ۦa�W��"+obj->name() +          "�A�|�F�@�f��j�C\n",({ me }));
    return notify_fail("�A���W�S���o�˪F��C\n");
  }

  tell_object(me,HIW"�i"NOR+ obj->name() +HIW"�j\n\n"NOR);

  if((string)obj->query("weapon_prop/damage"))
    tell_object(me,HIR"�� �� �O"NOR""WHT"�G" + obj->query("weapon_prop/damage")+"\n");
  else if((string)obj->query("armor_prop/damage"))
    tell_object(me,HIR"�� �� �O"NOR""WHT"�G" + obj->query("armor_prop/damage")+"\n");
  else
    tell_object(me,HBK"�� �� �O"NOR""WHT"�G0\n");

  if((string)obj->query("armor_prop/armor"))
    tell_object(me,HIC"�� �m �O"NOR""WHT"�G" + obj->query("armor_prop/armor")+"\n");
  else
    tell_object(me,HBK"�� �m �O"NOR""WHT"�G0\n");
 
  if((string)obj->query("armor_prop/shield"))
    tell_object(me,HIG"���F��ܤO"NOR""WHT"�G"+obj->query("armor_prop/shield")+"\n"NOR);
  else
    tell_object(me,HBK"���F��ܤO"NOR""WHT"�G0\n"NOR);

  if((string)obj->query("value"))
    tell_object(me,HIY"���~����"NOR""WHT"�G" + obj->query("value") + "\n"NOR);
  else
    tell_object(me,HBK"���~����"NOR"�G�@�夣��\n");

  tell_object(me,HIW"\n  �˳Ʊ���"NOR"�G\n");
  i=8; 
  switch(i)
  {
    case 8:
         if(obj->query("limit_lv"))
           limit+="            �һݵ��šG"+obj->query("limit_lv")+"\n";
    case 7:
         if(obj->query("limit_skill"))
           limit+="            �һݧޥ��G"+obj->query("limit_skill")+"\n";
    case 6:
         if(obj->query("limit_str"))
           limit+="            �һݤO�q�G"+obj->query("limit_str")+"\n";
    case 5:
         if(obj->query("limit_dex"))
           limit+="            �һݱӱ��G"+obj->query("limit_dex")+"\n";
    case 4:
         if(obj->query("limit_int"))
           limit+="            �һݴ��z�G"+obj->query("limit_int")+"\n";    
    case 3:
         if(obj->query("limit_con"))
           limit+="            �һ����G"+obj->query("limit_con")+"\n";  
    case 2:
         if(obj->query("limit_exp"))
           limit+="            �һݸg��ȡG"+obj->query("limit_exp")+"\n";
    case 1:
         if(sizeof(limit)<1)
           limit+="            �L\n";        
  }
  tell_object(me,limit);
  tell_object(me,HIW"\n  �W�[�ݩ�"NOR"�G\n");
  i=23; 
  switch(i)
  {
    case 23: 
         if(obj->query("weapon_prop/str"))
           other+="            �O�q(STR)�G"+obj->query("weapon_prop/str")+"\n";
    case 22: 
         if(obj->query("weapon_prop/con"))
           other+="            ���(CON)�G"+obj->query("weapon_prop/con")+"\n";
    case 21: 
         if(obj->query("weapon_prop/int"))
           other+="            ���z(INT)�G"+obj->query("weapon_prop/int")+"\n";
    case 20: 
         if(obj->query("weapon_prop/dex"))
           other+="            �ӱ�(DEX)�G"+obj->query("weapon_prop/dex")+"\n";
    case 19: 
         if(obj->query("weapon_prop/hit"))
           other+="            �����R���v�G"+obj->query("weapon_prop/hit")+"\n";
    case 18:
         if(obj->query("weapon_prop/dodge"))
           other+="            �{���j�ײv�G"+obj->query("weapon_prop/dodge")+"\n";
    case 17:
         if(obj->query("weapon_prop/bio"))
           other+="            �ͪ�(BIO)�G"+obj->query("weapon_prop/bio")+"\n";
    case 16:
         if(obj->query("weapon_prop/bar"))
           other+="            �~��(BAR)�G"+obj->query("weapon_prop/bar")+"\n";
    case 15:
         if(obj->query("weapon_prop/wit"))
           other+="            �]�k(WIT)�G"+obj->query("weapon_prop/wit")+"\n";
    case 14:
         if(obj->query("weapon_prop/sou"))
           other+="            ���F(SOU)�G"+obj->query("weapon_prop/sou")+"\n";
    case 13:
         if(obj->query("weapon_prop/tec"))
           other+="            ���(TEC)�G"+obj->query("weapon_prop/tec")+"\n";      
    case 12: 
         if(obj->query("armor_prop/str"))
           other+="            �O�q(STR)�G"+obj->query("armor_prop/str")+"\n";
    case 11: 
         if(obj->query("armor_prop/con"))
           other+="            ���(CON)�G"+obj->query("armor_prop/con")+"\n";
    case 10: 
         if(obj->query("armor_prop/int"))
           other+="            ���z(INT)�G"+obj->query("armor_prop/int")+"\n";
    case 9: 
         if(obj->query("armor_prop/dex"))
           other+="            �ӱ�(DEX)�G"+obj->query("armor_prop/dex")+"\n";
    case 8: 
         if(obj->query("armor_prop/hit"))
           other+="            �����R���v�G"+obj->query("armor_prop/hit")+"\n";
    case 7:
         if(obj->query("armor_prop/dodge"))
           other+="            �{���j�ײv�G"+obj->query("armor_prop/dodge")+"\n";
    case 6:
         if(obj->query("armor_prop/bio"))
           other+="            �ͪ�(BIO)�G"+obj->query("armor_prop/bio")+"\n";
    case 5:
         if(obj->query("armor_prop/bar"))
           other+="            �~��(BAR)�G"+obj->query("armor_prop/bar")+"\n";
    case 4:
         if(obj->query("armor_prop/wit"))
           other+="            �]�k(WIT)�G"+obj->query("armor_prop/wit")+"\n";
    case 3:
         if(obj->query("armor_prop/sou"))
           other+="            ���F(SOU)�G"+obj->query("armor_prop/sou")+"\n";
    case 2:
         if(obj->query("armor_prop/tec"))
           other+="            ���(TEC)�G"+obj->query("armor_prop/tec")+"\n";      
    case 1:
         if(sizeof(other)<1)
           other+="            �L�B�~�ݩ�\n";         
  }
  tell_object(me,other);

  if(obj->query("female_only")) tell_object(me,HIM"\n�k�ʱM�θ˳�\n"NOR);
  if(obj->query("male_only")) tell_object(me,HIC"\n�k�ʱM�θ˳�\n"NOR);      
  if(obj->query_autoload()) tell_object(me,HIR"\n�i�x�s�˳�\n"NOR);

  return 1;
}
