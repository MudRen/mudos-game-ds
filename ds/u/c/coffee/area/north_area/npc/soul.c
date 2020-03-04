#include <ansi.h>
inherit NPC; 
mapping *combat_action = ({
        ([      "action":  
   "$N�ϥX�F�}��Ӱ}�աA�I�i"HIR"�u"HIC"���δ��v"HIR"�v"NOR"�A�M��t����ŧ$n�A��$n���W�X�{�F�Ʊ��岪�I�I",
                "attact_type":  "dex",
                "damage" : 700,
                "damage_type":  "�g�w��",
        ]),
        ([      "action":  
   "$N�������O�A�I�i���ƪ�"HIG"�i"HIR"�{�F"HIB"��"HIB"�]"HIY"��"HIG"�j"NOR"�A�y��"HIR"��������"NOR"�A����$n���ݤf�A��$n�L�k�۬[�A�ϩ��ݤf�N�z���}�ӡI�I",
                "attact_type":  "bar",
                "damage" : 600,
                "damage_type":  "�z����",
        ]),
        ([      "action":
   "$N�q���F�@�D�G�y"HIG"�y"HIB"�_��G"HIG"�z"NOR"�A�y�ɦa���g�_�A�ϩ��n���}�F�I�I�y�ɾ_�ˤF$n�A�ɭP$n�R�F�f�A��I",
               "attact_type":  "con",
                "damage" : 800,
                "damage_type":  "�ж�",
        ]),
});

void do_clean();

void create() 
{ 
  set_name(HIR"�v����"NOR, ({ "umbra-claw soul", "soul" }) );
  set("race", "human");
  set("level",60);
  set("max_hp",15000); 
  set("str",120); 
  set("con",120); 
  set("int",100); 
  set("dex",100); 
  set("title",HIR"��"HIC"�v"HIW"��"HIY"��"NOR);
  set("combat_exp",1000000); 
  set("attitude","friendly");
  set("long",@LONG        
�e�ݰ_�ӤQ���Ź��A���O�����T�Q���i�ȡC�e�쥻�O�b�}�f
����~��A�u�@�۪��񪺰ʪ����~�C���O�]���������t�A�e
�D��s�Y��U�Ӫ��s�����A�ߤ��}�l�ؤU���뤧�N�C�e�}�l
�����~��b�o�ӥj�}�ު��F�@�d�~�C�ݵۨe���������l�A��
�T���H�P�쮣�ߡI�I
LONG); 

  setup();
   carry_object("/u/c/coffee/area/north_area/eq/soul_armor")->wear();
  set("actions", (: call_other, __FILE__, "query_action" :));
  carry_object("/u/c/coffee/area/north_area/eq/soul_armor")->wear();

}
 mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
HIB"\n\t��"HIY"�d�~�j�}"HIB"��"HIG"�A�j�}�̬��D�@�諸����"HIB"�u"HIR"�v����"HIB"�v"HIG"�ש�Q�i�h"HIC+ob->name(1)+HIG"�����F�I�I\n\n"+NOR,users());
        ob->add("popularity", 5); //�n��
  switch( random(100) )
  {
    case  0..10: new("/u/c/coffee/area/north_area/wp/soul-sword")->move(this_object());
          break;
  }
        tell_object(ob,HIG"(�]���A�����F�v����A�ҥH�o��F 5 �I�n��C)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

