
// cleanup.c

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object *ob_list;
        int old_size, i;

        if (!str) return notify_fail("���O�榡�Rcleanup2 <�ɦW>\n"); 

        str = resolve_path(me->query("cwd"), str);
        ob_list = children(str);
        old_size = sizeof(ob_list);
        ob_list->clean_up();
        for(i=0; i<sizeof(ob_list); i++) {
                destruct(ob_list[i]);
        }
        ob_list -= ({ 0 });
        printf("�M�� %d �Ӫ���C\n", old_size - sizeof(ob_list));
        return 1;
}

int help(object me)
{
        write(@HELP
���O�榡�Rcleanup <�ɦW>

��Ҧ����w�ɦW������I�s clean_up�M�åB�M���Ҧ��Q�ƻs�X�Ӫ�����C
HELP
        );
        return 1;
}

