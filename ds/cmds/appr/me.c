// /cmds/wiz/me.c
//
// Kenny@Broken.History (6/18/1996)

inherit F_CLEAN_UP;
inherit "/feature/vi";                           // �~�ӽs��\��

int file_exists(string file);

int main(object me, string arg)
{
        string file, oldfile;
        object ob;

        if (in_edit(me)) return notify_fail("�A�w�g�b�ϥνs�边�F�C\n");
        if (!arg) return notify_fail("���O�榡�Gme <�ɦW>|<����W>\n");

        seteuid(geteuid(me));
        file = resolve_path(me->query("cwd"), arg); // ���o�ɦW
        if (!file_exists(file)) // check virtual object
        {
                string *path=explode(file, "/");
                oldfile = file;
                file = "/"+implode(path[0..<2], "/")+"/_"+path[<1];
        }
        if (!file_exists(file))
        {       // �s��
                ob = present(arg, me);  // �ˬd���W������
                if (!ob) ob = present(arg, environment(me)); // �ˬd�ж���������
                if (ob && me->visible(ob))
                        file = base_name(ob) + ".c"; // ���o�����ɦW
                else    file = oldfile;
        }

        start_edit(file);               // �I�s�s�边�A�}�l�s��
        return 1;
} // main()

int file_exists(string file)
{
        if (!stringp(file) || file=="") return 0;
        return file_size(file)>=0;
}

int  help(object me)
{
        write(@HELP
���O�榡�Gme <�ɦW>|<����W>

�Q�Φ��@���O�i�����b�u�W�s���ɮסA�Բӻ����Ьݽs�边�����u�W���U�����C

�������O�Gedit�Bupdate�C
HELP
                );
        return 1;
} // help()
