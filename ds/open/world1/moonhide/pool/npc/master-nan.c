#include <ansi.h>
inherit NPC; 
mapping *combat_action = ({
        ([      "action":               "$N�񯸤K�����椧��A�ϥX�@���u"HIG"�L�j�}��"NOR"�v�٨�������쪫��P���A$n�y�ɷw�t�A����˦a",
                "attact_type":  "bar",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
                "damage" : 200,
                "damage_type":  "�w�t��",
        ]),
        ([      "action":               "$N���x�@�u�A�ϥX�@���u"HIM"�k�E���@"HIY"��"NOR""MAG"����F��"NOR"�v�A���t������A�K�A�ɪ����X�@�x�A$n���_��H������A���X�Q���~!!",
                "attact_type":  "bar",
            "damage" : 300,
                "damage_type":  "�ж�",
        ]),
        ([      "action":               "$N���ۻy��A�ϥX�@�۳N�u"HIY"���ťE�Ѷ}"NOR"�v�D�D�s���A�N��$n����!!",
                "attact_type":  "int",
            "damage" : 400,
                "damage_type":  "�N��",
        ]),
    ([  "action":       "$N��M�b���V$n�A�ΤO������$n!!",
                "attact_type":  "bar",
            "damage" : 500,
                "damage_type":  "����",
        ]),
    ([  "action":       "$N���x�ۦp�A���a��̤߼C�A�K�Ƥ��O���C�B�߼C���ߡA�y�ɶ��ƹD�C��A���V$n!!",
                "attact_type":  "sou",
            "damage" : 600,
                "damage_type":  "�h�B����",
        ]),
   
   
});

void do_clean();

void create() 
{ 
  set_name(HIW"�n�c�L��"NOR,({"master nan","nan"}));
  set("race", "human");
  set("level",77);
  set("max_hp",193021); 
  set("age",27);     
  set("combat_exp",1000000); 
  set("attitude","friendly");
  set_skill("sword",100);
  set_skill("blade",100);
  set_skill("block",100);
  set_skill("dodge",100);
  set_skill("blade",100);
  set_skill("whip",100);
  set_skill("axe",100);
  set_skill("force",100);
  set_skill("unarmed",100);
  set_skill("parry",100);
  set_skill("anti_poison",100);
  set_skill("chess",100);
  set_skill("literate",100);
  set_skill("swim",100);
  set_skill("gun",100);
  set_skill("hammer",100);
  set_skill("bow",100);
  set_skill("throwing",100);
  set("devil",40000); 
  set("long",@LONG        
�n�c�ݤѪ���̡A���@�ͧ@�c�h�ݡA�̫�Q�n�c�K�ߡB�n�c�ݤ�
���H�A�I�i�ʦL�N�A�ʦL�b���P�H�}�̡C
LONG); 
  setup(); 
  set_living_name("pool_npc");
  carry_object(__DIR__"obj/mie-blade")->wield();
  carry_object(__DIR__"obj/sky-pearl")->wear();
  carry_object(__DIR__"obj/dragon-boots")->wear();
  carry_object(__DIR__"obj/tiger-mask")->wear();
  carry_object(__DIR__"obj/purple-kasaya")->wear();

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
        message_vision(HIR"\n\t\t$N�b�{�����e�A�ש�ϥX�ۧڵ��Ǣw�u"HIW"�ѥ~�����g"HIR"�v�I�I\n"NOR,this_object());
        message_vision(HIY"\n$N���t���Фѥ~�����g�ߪk�A�ñN�����ǿķ|�e�q�I�I\n"NOR,this_object(),ob);
        message_vision(HIG"\t\n�����u����¶�b$N�P��A���趡$N�ϥX�ѥ~�����g�Ҧ��ۦ��I�I"NOR,this_object(),ob);
        message_vision(HIW"$N�ϥX"HIG"�ѥ~�����g"HIR"�Ĥ@��"HIY"�m"HIC"��C�Ѧa"HIY"�n"HIW"�����F��A�]��"HIR"$N"HIW"�A�f�t�Ҫk�д��\\�A�r�O�@���V$n�I�I\n"NOR,this_object());
        message_vision(HIY"\t\n$n�Ӥ��ΰ{���A�D��$N���r�P����"NOR,this_object(),ob);
        message_vision(HIW"$N�ϥX"HIG"�ѥ~�����g"HIR"�ĤG��"HIY"�m"HIG"�N�u���["HIY"�n"HIW"�����Q��A�]��"HIR"$N"HIW"�A�f�t�Ҫk�д��\\�A�r�O�@���V$n�I�I\n"NOR,this_object());
        message_vision(HIY"\t\n$n�Ӥ��ΰ{���A�D��$N���r�P����"NOR,this_object(),ob);
        message_vision(HIW"$N�ϥX"HIG"�ѥ~�����g"HIR"�ĤT��"HIY"�m"HIM"�������~"HIY"�n"HIW"��������A�]��"HIR"$N"HIW"�A�f�t�Ҫk�д��\\�A�r�O�@���V$n�I�I\n"NOR,this_object());
        message_vision(HIY"\t\n$n�Ӥ��ΰ{���A�D��$N���r�P����"NOR,this_object(),ob);
        message_vision(HIW"$N�ϥX"HIG"�ѥ~�����g"HIR"�ĥ|��"HIY"�m"HIC"�p���L��"HIY"�n"HIW"�����u��A�]��"HIR"$N"HIW"�A�f�t�Ҫk�д��\\�A�r�O�@���V$n�I�I\n"NOR,this_object());
        message_vision(HIY"\t\n$n�Ӥ��ΰ{���A�D��$N���r�P����"NOR,this_object(),ob);
        message_vision(HIW"$N�ϥX"HIG"�ѥ~�����g"HIR"�Ĥ���"HIY"�m"HIC""BLK"�]�E�ѤU"HIY"�n"HIW"��������A�]��"HIR"$N"HIW"�A�f�t�Ҫk�д��\\�A�r�O�@���V$n�I�I\n"NOR,this_object());
        message_vision(HIY"\t\n$n�Ӥ��ΰ{���A�D��$N���r�P����"NOR,this_object(),ob);
        message_vision(HIW"$N�ϥX"HIG"�ѥ~�����g"HIR"�̲׳�"HIY"�m"HIW"�E"HIG"��"HIY"��"HIW"��"HIY"�n"HIW"�����Ǯ�A�]��"HIR"$N"HIW"�A�f�t�Ҫk�д��\\�A�r�O�@���V$n�I�I\n"NOR,this_object());
        message_vision(HIY"\t\n$n�Ӥ��ΰ{���A�D��$N���r�P����"NOR,this_object(),ob);
        message_vision(HIR"\n\t\t$n"HIR"�Q$N"HIR"���ѥ~�����g������A����L�񪺳жˡA���߭ѯh�I�I\n"NOR,this_object());
        ob->receive_damage("hp",ob->query("hp")*19/20);
        COMBAT_D->report_status(ob);
        message("world:world1:vision",
                HIW"\n\t�i"HIG"�Z�L����"HIW"�j "HIR"�h���@���Z�ǫn�c�L���A�רs����"HIG+ob->name(1)+HIR"���O�A�ѾԤF�U�ӡI�I\n
                "HIM"\n\t�ݩ�"HIW"�n�c�L�������R�P�y�ɮ��u�L�סI�I\n\n"+NOR,users());
        ob->add("popularity", 5); //�n��
        tell_object(ob,HIG"(�]���A�����F�n�c�L���A�ҥH�o��F 7 �I�n��C)"NOR);
        ::die();
        //destruct(this_object());
        return;
}
