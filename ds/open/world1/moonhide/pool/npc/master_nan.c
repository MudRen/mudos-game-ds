#include <ansi.h>
inherit NPC; 
mapping *combat_action = ({
        ([      "action":               "$N�⮳"HIR"�]���L"NOR"�񯸤K�����椧��A�ϥX�@���u"HIG"�L�j�}��"NOR"�v�٨�������쪫��P���A$n�y�ɷw�t�A����˦a",
                "attact_type":  "bar",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
                "damage" : 200,
                "damage_type":  "�w�t��",
        ]),
        ([      "action":               "$N�]�M�@�u�A�ϥX�@���u"HIM"�k�E���@"HIY"��"NOR""MAG"����F��"NOR"�v�A���t������A�K�A�ɪ����X�@�x�A$n���_��H������A���X�Q���~!!",
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
    ([  "action":       "$N���x�ۦp�A���a��̤ߤM�A�K�Ƥ��O���M�B�ߤM���ߡA�y�ɶ��ƹD�M�v�A���V$n!!",
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
  set("max_hp",12000); 
  set("age",27);     
  set("title",HIG"�n�c�@�a");
  set("nickname",HIC"�@�a�ߤM�ǤH"NOR);
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
        message_vision(HIR"\n\t$N"HIR"�b�{�����e�A�ש�ϥX�ۧڵ��Ǣw�u"HIW"�ѥ~�����g"HIR"�v�I�I"NOR,this_object());
        message_vision(HIY"\n\t$N"HIY"���t���Фѥ~�����g�ߪk�A�ñN�����ǿķ|�e�q�I�I"NOR,this_object(),ob);
        message_vision(HIG"\n\t�����u����¶�b$N"HIG"�P��A���趡$N"HIG"�ϥX�ѥ~�����g�Ҧ��ۦ��I�I\n\n"NOR,this_object(),ob);
        message_vision(HIW"�n�c�L��"HIW"�ϥX"HIG"�ѥ~�p���g"HIR"�Ĥ@��"HIY"�m"HIC"��C�Ѧa"HIY"�n"HIW"�����F��A�]��"HIR"$N"HIW"�A�M��r�O�@���V"+ob->name(1)+HIW"�I�I\n"NOR,this_object());
        message_vision(HIY"\t($n�Ӥ��ΰ{���A�D��$N"HIY"���r�P����)\n"NOR,this_object(),ob);
        message_vision(HIW"�n�c�L���ϥX"HIG"�ѥ~�p���g"HIR"�ĤG��"HIY"�m"HIG"�N�u���["HIY"�n"HIW"�����Q��A�]��"HIR"$N"HIW"�A�M��r�O�@���V"+ob->name(1)+HIW"�I�I\n"NOR,this_object());
        message_vision(HIY"\t($n�Ӥ��ΰ{���A�D��$N"HIY"���r�P����)\n"NOR,this_object(),ob);
        message_vision(HIW"�n�c�L���ϥX"HIG"�ѥ~�p���g"HIR"�ĤT��"HIY"�m"HIM"�������~"HIY"�n"HIW"��������A�]��"HIR"$N"HIW"�A�M��r�O�@���V"+ob->name(1)+HIW"�I�I\n"NOR,this_object());
        message_vision(HIY"\t($n�Ӥ��ΰ{���A�D��$N"HIY"���r�P����)\n"NOR,this_object(),ob);
        message_vision(HIW"�n�c�L���ϥX"HIG"�ѥ~�p���g"HIR"�ĥ|��"HIY"�m"HIC"�p���L��"HIY"�n"HIW"�����u��A�]��"HIR"$N"HIW"�A�M��r�O�@���V"+ob->name(1)+HIW"�I�I\n"NOR,this_object());
        message_vision(HIY"\t($n�Ӥ��ΰ{���A�D��$N"HIY"���r�P����)\n"NOR,this_object(),ob);
        message_vision(HIW"�n�c�L���ϥX"HIG"�ѥ~�p���g"HIR"�Ĥ���"HIY"�m"HIC""BLK"�]�E�ѤU"HIY"�n"HIW"��������A�]��"HIR"$N"HIW"�A�M��r�O�@���V"+ob->name(1)+HIW"�I�I\n"NOR,this_object());
        message_vision(HIY"\t($n�Ӥ��ΰ{���A�D��$N"HIY"���r�P����)\n"NOR,this_object(),ob);
        message_vision(HIW"�n�c�L���ϥX"HIG"�ѥ~�p���g"HIR"�̲׳�"HIY"�m"HIW"�E"HIG"��"HIY"��"HIW"��"HIY"�n"HIW"�����Ǯ�A�]��"HIR"$N"HIW"�A�M��r�O�@���V"+ob->name(1)+HIW"�I�I\n"NOR,this_object());
        message_vision(HIY"\t($n�Ӥ��ΰ{���A�D��$N"HIY"���r�P����)\n"NOR,this_object(),ob);
        message_vision(HIR"\n"+ob->name(1)+HIR"�ӳ�����F$N"HIR"���ѥ~�p���g�����A����L�񪺳жˡA���߭ѯh�I�I\n"NOR,this_object());
        ob->receive_damage("hp",ob->query("hp")*19/20);
        COMBAT_D->report_status(ob);
        message("world:world1:vision",
                HIW"\n\t�i"HIG"�Z�L����"HIW"�j "HIR"�h���@���Z�ǫn�c�L���A�רs����"HIG+ob->name(1)+HIR"���O�A�ѾԤF�U�ӡI�I\n
                "HIM"\n\t�ݩ�n�c�L��"HIM"�����R�P�y�ɮ��u�L�סI�I\n\n"+NOR,users());
        ob->add("popularity", 5); //�n��
        tell_object(ob,HIG"(�]���A�����F�n�c�L���A�ҥH�o��F 5 �I�n��C)"NOR);
        ::die();
        //destruct(this_object());
        return;
}
