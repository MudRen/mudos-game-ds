#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
void create() {
	set_name(HIC"����"NOR,({"wind soul","soul","dagger"}));
	set("long",@LONG

�p�p���@������P���A�ݰ_�ӷL�����D�A���䤤ĭ�t�ۤ��i�����]
�O�A�ڻ��H�J�b�䤤��������|�l���ͪ����F��C
����šG�ŵL�@��
LONG
);
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("limit_dex",40);
    set("limit_int",25);
        set("unit", "��");        
        set("value",1000);
        set("volume",2);        
        set("material","crystal");               
               }
        set("soul_times",0);
        set("soul_levels",0);
	set("weapon_prop/bar",-1);
	init_dagger(20);
        set("backstab_bonus",10);
        set("class_only","thief");
        setup();
}    

void soul_lv(int lv)
{
 mixed level = ({"�ŵL�@��","�����Y�L","���Z�L�_","���O�즨","�������N",
                        "��㧯�O","���~�E�{","���O�j��","����R��","���~����",
                        "�H�ߩұ�","�l���«C","�`���i��","�n�p�y��","���ѷ��a",
                        "�s�����O","���O�L��",});
 int times,levels;
 times = this_object()->query("soul_times");
 levels = this_object()->query("soul_levels");
 times = times + lv;
 if (times >= (levels+1)*15 && levels < 50)
 {
  levels = levels +1;
  times = 0;
  write(HIR"����l���F��������z�A�¤O��W�@�h�ӡC\n"NOR);
  if(levels<=33) set("long","�p�p���@������P���A�ݰ_�ӷL�����D�A���䤤ĭ�t�ۤ��i�����]\n"+
                "�O�A�ڻ��H�J�b�䤤��������|�l���ͪ����F��C\n"+
                "����šG"+level[levels/2]+"\n");
  set("soul_levels",levels);
  this_object()->unequip();
  init_dagger(20+levels);
  this_object()->wield();
  set("backstab_bonus",10+levels);
 }
 set("soul_times",times);
 return;
}

void attack(object me,object victim)
{
 int lv;

  ::attack();
 if (((!victim) || (victim->query("hp") < 0)))  //�䤣�������H(�i�ॴ��mob�bquery��hp<0�e���})
 {                                               //�άO����mob�æb���query��mob hp<0
  if(victim) lv=victim->query("level");
  else lv=1;
  message_vision(HIW"$N"HIW"�⤤������z�X�@�D���~�A�N�ݯd����z�l���C\n"NOR,me);
  soul_lv(lv * 2);
 }
 return;
}
