// wimpy.c

inherit F_CLEAN_UP;

int help(object me);
void delay(object me);

int main(object me, string arg)
{
        if( me->query_temp("cmds/inactive") )
                return notify_fail("�A�~��γo�ӫ��O, �A���@�|��A�ϥΧa�C\n");

        me->set_inactive(1);
        write(@README
�A�N�ۤv�]�w��[���m�Ҧ�]�A�H�קK�o�b�Ӥ[�ӳQ�j�����u�C
[�`�N: ���Ҧ������i��Q�����A�п�ܦw�������m��m�C ]

README
);
        me->set_temp("cmds/inactive", 1);
        call_out("delay", 300, me);
        return 1;
}

void delay(object me)
{
        if( !me ) return;
        me->delete_temp("cmds/inactive");
}

void remove_call() { remove_call_out("delay"); }

int help(object me)
{
        write(@HELP
���O�榡�R inactive

�o�ӫ��O���A�]�w���u���m�Ҧ��v�A���Ҧ��N����@���Ͳz����C
�H�K���a�{�ɦ��Ʀӥ������}�@�q�ɶ��A�`�N���Ҧ������i��D�������C
(�ثe�̤j���m�ɶ������p�ɡA�]�N�O300����)

HELP
        );
        return 1;
}

