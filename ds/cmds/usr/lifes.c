// lifes.c
// �T�ध��A�i�H�ǲߥͬ��ޯ�

#include <ansi2.h>

inherit F_CLEAN_UP;
int sort_skill(string sk1,string sk2);

int main(object me, string arg)
{
        object ob;
       string basic;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("�A�n��ݽ֪��ͬ��ޯ�S\n");
        }

        if( ob!=me      && !wizardp(me)         && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) )
                return notify_fail("�u���Ův�Φ��v�{���Y���H���ݥL�H���ޯ�C\n");


        basic   = "�x"+BBLU HIW "  �� �� �� ��                              ����    ���m�� / �ɯŻݭn    "+NOR"�x\n"NOR;
        basic += "����������������������������������������������������������������������������\n";
        
        basic = "�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n"
                + basic
                + "�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";

        write(basic);
        return 1;
}

int help(object me)
{
        write(@HELP
���O�榡 : lifes [<�Y�H>]

�o�ӫ��O�i�H���A(�p)�d�ߩҾǹL���ͬ��ޯ�C

�Ův�i�H�d�ߥ���H�� NPC ���ޯબ�p�C

HELP
    );
    return 1;
}

