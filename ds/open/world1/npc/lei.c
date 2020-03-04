#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��", ({ "lei","lei" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",31);
        set("age",random(100));
        set("evil",-15);
        set("title",HIR"�t���ƨ�"NOR);
        set("long",@LONG
�ժ����e���N�����A�j�a���s�L�u�L�Ρv�����A���ɬO�Q�C
�K���֤k�A���ɬO�C�K�Q���ѱC�C�A�̾ժ��Ω��e�N�t�X��
�N�ӻX���ĤH�A�H�F���ت��C
LONG
);
        set_skill("sorgi_sword",60);
        set("chat_chance_combat",26);
        set("chat_msg_combat", ({
                  (: command("exert sorgi_sword") :),
        }) );
        setup(); 
        carry_object(__DIR__"../eq/ws_cloth")->wear();
        carry_object(__DIR__"../wp/th_sword")->wield();
}

void die()
{
	object killer;
	int last;
	if(random(7))
	{
		if(killer=this_object()->query_temp("last_damage_from"))
		{
			last = killer->query("max_hp")/10;
			if(last < killer->query("hp"))
			{
				message_vision(HIW"  $N�κɳ̫�@�I�O��ϥX"HIR"�d�C��"HIW"  $n�@�ɤ������εw�O�Y�U�o�ۡC\n"NOR,this_object(),killer);
				last=killer->query("hp")-last;
			        killer->receive_damage("hp",last,this_object());
			}
		}
	}
	::die();
}
