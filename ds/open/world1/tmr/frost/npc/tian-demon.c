#include <ansi.h>

inherit NPC;
varargs int receive_damage(string type, int damage, object who);
void do_combat_attack();
mapping *combat_action = ({
        ([  "action":       "$N����@���A�ƹD�G��⪺���~���g�V$n��$l",
                "attact_type":  "bio",
                "damage_type":  "���",
        ]),
});

/* �۩w�԰��T�� */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}


void create()
{
        set_name("�ѧ�" ,({"tian demon","demon", "_TIAN_DEMON_" }) );
        set("long",@LONG
�u�ѧ��v�۽Y�j�}�ѫ�A�N�M�H�������ͦs��{�b�A�ѩ�ѧ��O�Ѳ�
�H���ߤ������c���Y�Ҳֿn�λE�Ӧ����A���c���H�V�h�A�ѧ����O�q�V�O
�j�j�B���`�V�j�A���n����B�D�������H�h���O�s�ӵ��ڡA�H���H�@����
�c���A�p���~�৹�����h�����A�ҿסu�ꤧ�N�`�B�������^�v�A�]�O����
���o�ؤd�~�׮`�C
LONG
);
        set("age",200);
          set("race","evil");
        set("title","�U�c����");
        set("level",60);
          set("race","evil");
        set("attitude", "aggressive");
        set("gender", "�k��" );
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
                (:do_combat_attack():),
        }) );
        setup();
                set("default_actions", (: call_other, __FILE__, "query_action" :));
                set("actions", (: call_other, __FILE__, "query_action" :));

        set_living_name("_NPC_TIAN_DEMON_");
        set_temp("apply/armor",100);
          set_temp("apply/hit",120);


        carry_object(__DIR__"wp/devil-dagger")->wield();
          if( random(100) < 30)  
                carry_object(__DIR__"eq/tian-demon_cloak")->wear();
        else
                carry_object(__DIR__"eq/tian-demon_cloak2")->wear();

        carry_object(__DIR__"eq/thousandbone-shield")->wear();
}
// �԰������S��
void do_combat_attack()
{
        object ob=this_object();
        object* targets;
        int i,j;
        
        targets=ob->query_enemy();
        if( sizeof(targets) > 1
	&& random(100)>70 
        )  {
        message_vision(HIM"\n$N�i�L�R�X�F�@�f���B�Ӹ{��������.....\n"NOR,ob);
                for(i=0;i<sizeof(targets);i++)
                {
                        // �ä����c
                        if(targets[i]->query("evil")<400 ) {
                                tell_object(targets[i],CYN"\n(�A�ߤ����ڰ�w�A�èS���������𪺼v�T�C)\n"NOR);
                                ob->add("evil",10);
                                continue;
                        }
                        j=random(sizeof(targets));
                        // �P�@�H..
                        if( targets[i]==targets[j] ) continue;
                        // �o�G�H�w�g�b�԰��F
                        if(targets[i]->is_fighting( targets[j]) ) continue;
                        // ���o�G�H���_��...
                        tell_object(targets[i],HIR"\n(�A�l�J�F�ֳ\\����A��Ĳ�ʧA�ߤ��������A�A�}�l�Q���H�F�I�I�I�C)\n" NOR);
                        targets[i]->fight_ob(targets[j]);
                        targets[j]->fight_ob(targets[i]);
                        message_vision(HIR "$N���M�}�l����$n�I�I\n" NOR,targets[i],targets[j]);             
                } // end for
         }
         else {
                // �ɦ�
                if(ob->query("hp") < ob->query("max_hp")/2) {
                        message_vision(HIG"$N�B�_�u���]�j�k�v�A���W���˪���׽w�w�a�ǩM�F�C\n"NOR,ob);
                        ob->receive_heal("hp",100+random(50) );  
                } else {
                        ob->attack();
                }
         } //end if
              command("wield dagger");
}

// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<30)
                {
                        damage/=2;
                        message_vision(HIM "\n$N���e�~�a�X�{�@���p���A�N$N���h�F�j�b���ˮ`�C\n" NOR,this_object());
                }
        if(damage<1) damage = 1;

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
}

void die()
{
        object ob,energy=new(__DIR__"obj/energy");
        energy->move(this_object() );

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
 
                message("world:world1:vision",
        HIG"\n\t�i�D�������j�G"+HIM"�������ݪ��u�ѧ��v���R�P�Q"+ob->name(1)+"����F.....\n\n"+NOR
        ,users());
         ob->add("popularity",3); //�n��
         tell_object(ob,HIG"�A�o��T�I�n��F�C"NOR);
        ::die();
        return;
}

