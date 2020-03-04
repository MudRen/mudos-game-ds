#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�j�s", ({ "bandits" }) );
        set("long","�ݰ_�Ӥ@�y�����c�٪��ˤl�A�`�`��㤣�����A�ٷ|�L�G�X�⥴�H�A�m\n"
                   "���H���]���C\n");
        set("level",20+random(10));
        set("age",18+random(3));

        set("chat_chance", 4);
        set("chat_msg", ({
  "�j�s���G�֧⨭�W������X��\n",
  "�j�s���G�n���n�R...\n"
}));
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (:command("say ������a�A�����F�ơI"):),
                (:command("wield all"):),
                (:command("say �ֵ������M���A���a�I"):),
                (:command("say �y��Ѥl���z�I�I�I�������ڡA���o���@�ФF�I"):),
                       }) );
        
        set_skill("blade", 80);
        set_skill("parry", 70);
        set_skill("unarmed", 76);
        set_skill("dodge", 65);

        setup();
        carry_object(__DIR__"obj/steelblade")->wield();
        carry_object(__DIR__"obj/banditspants")->wear();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
   if(!me || !target) return 0;
    if(random(4)) return 0;
     if( !me->query_temp("weapon") ) return 0; 
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance/2) > tdex+tcon)
    {
      message_vision("\n"
                    +HIR"$N�j�ۤ@�n �y��Ѥl���z�A���n�R���ĦV$n�A���M�ì�......\n"
                    +"$N���t�a��$n���W�h�A$n�{�פ���A���F�ƤM\n"NOR
                    ,me,target);
      target->receive_damage("hp",50+random(50), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N�j�ۤ@�n �y��Ѥl���z�A���n�R���ĦV$n�A���M�ì�......\n"
                    +"$N���t�a��$n�A���O$n�b�d�v�@�v���ک��k��{......\n"
                    +"$n���M�{�L$N�����������A���٬O���p�߳Q$N��W�����M����ˤF......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",25+random(25), this_object());
      return 1;
    }
}



