#include <ansi.h>
#include <path.h>
inherit NPC;
void create()
{
        set_name("�B����", ({ "bu liu hu","bu","hu" }) );
        set("title", HIR"������n�P"NOR);
        set("gender", "�k��" );
        set("long",@long
	�B�������O�@�ӦI���H, �b�F�v�j�|�Q�ﲧ�ګ�, �y����
	�P, ����Q�C����}�l�ǲߦK��, �ѽ�[����Ѫ��V�O, �b�G�Q
	�|���ɫK�P���Ѥ���x��§, �]�]��ì�o�F������n�P���ٸ�.
	����S������ƭ���ä����Z�L�H�Ʊ���, �b�@���Q�ۤv���ҥ�
	�y���Z���˫�K�h���즹, ���L�L�����٬O�|���Z�L�H�����y
	�Ψ�.
	long
        );      
        set("age",56);
        set("level",30);
        set("race","human");
        set("chat_chance", 10);
        set("chat_msg", ({
             "�B�����ĹD�G�̪񳣨Sԣ���쪺�Ӥu��...�C\n",
	     "�B�����ĤF�@�f����\n",
	     "�B�����ۨ��ۻy�D: �����v���L���p��F ?\n",
        }));

        set("chat_chance_combat", 50 );        
        set("chat_msg_combat", ({
                "�B�����󪺤@�n, ���G�Q�����h.\n",
         }) );
  
        setup();
}

int accept_object(object who,object ob,)
{
        
        if(ob->query("id")!="coin" ) return 0;
        if (ob->query_amount() == 500)
        {
                command("nod");
                message_vision(HIY "$N�N���ʤ���浹�B����.�C\n" NOR ,who);
                who->receive_money(- ob->query_amount() );
                message_vision(HIY "$N�p�S�̻ݭn�Ǥ��� ?�C\n" NOR ,who);
                return 1;
        }

        return 1;
}
