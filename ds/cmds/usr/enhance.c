// enhance.c �ϥΥ[�j���b
// -Tmr 2007/04/26

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string arg1, arg2;
        string id;
        string s1,s2;
        object scroll, obj, ppl;
        int idx;

        if(!arg || arg == "-query") {
                // �C��
                me->start_more( ENHANCE_D->listScroll(me) );
                return 1;
        }

        if( sscanf(arg, "-put %s", arg1) == 1) {
                // �x�s
                if(!objectp(scroll = present(arg1, me)) )
                        return notify_fail("�A���W�S���o�رj�ƨ��b�C\n");
                ENHANCE_D->depositScroll(me, scroll);
                return 1;
        }


        
        if( sscanf(arg, "-get %d", idx) == 1 && ( arg == "-get " + idx) ) {
                // ���
                ENHANCE_D->withdrawScroll(me, idx);
                return 1;
        }

        if( sscanf(arg, "-get %s", id) == 1  ) {
                // ���
                ENHANCE_D->withdrawScroll_ID(me, id);
                return 1;
        }

        if( sscanf(arg, "%s on %s", arg1, arg2) != 2 ) {
                if( sscanf(arg, "%s", id) == 1 && wizardp(me) ) {
                    ppl = find_player(id);
                    if( !objectp(ppl) )
                        return notify_fail("�S���o�Ӫ��a�C\n");
                             // �C��
                             me->start_more( ENHANCE_D->listScroll(ppl) );
                        return 1;
                }
                return notify_fail("�� help enhance�A��o�ԲӪ����O�榡�����C\n");
        }


        if(!objectp(scroll = present(arg1, me)) )
                return notify_fail("�A���W�S���o�رj�ƨ��b�C\n");
        if(!objectp(obj = present(arg2, me)) )
                return notify_fail("�A���W�S���o�تF��C\n");
        
        s1 = obj->query("name");
        s2 = scroll->query("name");
        if( ENHANCE_D->enhance(scroll, obj) == -1 ) {
                        // ���a���A�O���b news paper �W tmr 2007/05/03
                RECORD_D->add_scroll_record(
                sprintf( "[%s] %s(%s)" + NOR "�� %s " + NOR "�ϥΤ@�i %s" + NOR"�A���o�ͮ��ƪ��ƤF�C\n" NOR,
                        ctime(time()), me->query("name"), me->query("id"), s1, s2 )
                );
                }
        return 1;
}
 
int help(object me)
{
        write(@HELP
���O�榡 : 

1. enhance
   �d�߭ӤH���b�ܮw�����e�C
2. enhance -put [�j�ƨ��b]
   �x�s�@�i�j�ƨ��b�ܧA���ӤH���b�ܮw��
   �C���x�s�ݪ�O 100 coin ����O�C
3. enhance -get [index]
   ���X ��index�i �j�ƨ��b�C
4. enhance -get [id]
   ���X�Ĥ@�i���b�^��r�����X�{ id ���j�ƨ��b�C
5. enhance [�j�ƨ��b] on [�Z���Ψ���]
   ��@��Z���Ψ���ϥΥ[�j���b�C

�ܮw�i�s���b�i�ư򥻬�200�i�A����51�Ť���A
�C�@�ťi�h�s16�i�A��100�ŮɡA�@�i�H�x�s1000�i�C

�����]�w�A�аѦ� help scroll�C
HELP
);

    return 1;
}

