#include <ansi.h>
inherit NPC; 
mapping *combat_action = ({
        ([      "action":  
   "$N�ϥX�F�}��Ӱ}�աA�I�i"HIR"�u���δ��v�v"NOR"�A���ή����󳱼v�����A���M�{����ŧ$n��$l�I",
                "attact_type":  "bio",
                "damage" : 700,
                "damage_type":  "�g�w��",
        ]),
        ([      "action":  

	    "$N�������O�A�I�i���ƪ�"HIG"�i�{�F���]���j"NOR"�A�y�ɼƤ��ѩ󰭭�����������V$n$l�I",
                 "attact_type":  "bar",
                "damage" : 600,
                "damage_type":  "�z����",
        ]),
        ([      "action":
   "$N�q���F�@�D�G�y"HIG"�y�_��G�z"NOR"�A�y�ɦa���@�P�g�_�A�ϩ��n���}�F�I�I",
               "attact_type":  "sou",
                "damage" : 800,
                "damage_type":  "�_��",
        ]),
});

void do_clean();

void create() 
{ 
  set_name( "�v������", ({ "umbra-claw soul", "soul" }) );
  set("race", "human");
  set("level",50);
  set("max_hp",15000); 
  set("str",120); 
  set("con",120); 
  set("int",100); 
  set("dex",100); 
  set("combat_exp",1000000); 
  set("attitude","friendly");
  set("long",@LONG        
�e�ݰ_�ӤQ���Ź��A���O�����o�Q���i�ȡC�v������쥻�O�b�}�f
����~��A�u�@�۪��񪺰ʪ����~�A���o�b�@�����N�~��������s�Y�A
����ͨ��o�S������H�@�N���I�A�]���L����z�����R����H��������
�A�ۦ������~��b�d�~�j�}�A�w�g���`�F�����h�֪��ͪ��F�C�ݵۨe��
�����Q���A���T���H�P�쮣�ߡI�I
LONG); 

  setup();
   carry_object(__DIR__"eq/soul_armor")->wear();
   carry_object(__DIR__"wp/soul-blade")->wield();
  set("actions", (: call_other, __FILE__, "query_action" :));

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
              HIB"\n\t"HIG"�~��b�d�~�j�}���c�F�u�v������v�ש�Q�i��" + ob->name(1)+HIG"�����F�I\n"+NOR,users());
        ob->add("popularity", 2); //�n��
        tell_object(ob,HIG"(�A�o��F 2 �I�n��C)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

