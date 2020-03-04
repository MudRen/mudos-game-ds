/*

  3N Scriper 3N �K���Ȼs�y��
  �һ��ɮ�: 1.  ansi.h
            2.  3n_easy.c
  .... produced by Cominging 2001.5.13 12:00 AM

*/
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"3N �K���Ȼs�y��"NOR, ({ "3n scriper", "scriper" }));
        set_weight(1);
        set("long", @LONG

�@�x���p������, ��ᤣ�_�a�_�X�@�i�i���K����, �A�i�H�ϥ�

wrote {�ҭn�d�U����r}  �]�i�H�� to write �ӿ�J�j���r
                        �åB�i�H�ϥ� help nick ���� $NOR$
                        ������X�C
cleanup                 �M���Ҧ����K���C
checkup [0|1]           0 �ˬd�Ҧ����K���b���̡C
                        1 �[�ݥ������K���C

LONG
        );
        set("unit", "�x");
        setup();
}

void init()
{
        if( base_name(this_object()) != "/u/c/cominging/test/3n_scriper" )
        {
                write("�L�k�ƻs, �۰ʮ���..\n");
                destruct(this_object());
                return;
        }
        add_action("do_wrote", "wrote");
        add_action("do_cleanup", "cleanup");
        add_action("do_checkup", "checkup");
}

int do_wrote(string arg)
{
        object m_ez;

        if( !arg ) return notify_fail("�п�J�A�ҭn�d�������e..\n");
        m_ez = new(__DIR__"3n_easy.c");
        m_ez->set_long(arg);
        if( m_ez->move(environment(this_player())) )
        {
                message_vision("$N�R�R���g�U�@�i�K����, �򸨦b�a�W..\n", this_player());
                return 1;
        }
        else return notify_fail(HIR"�o�Ϳ��~�I�I\n"NOR);
}

int do_cleanup(string arg)
{
        object *obs;
        obs = children(__DIR__"3m_easy.c");
        if( sizeof(obs) > 1)
        {
                write("�T�w�n�M���Ҧ����K���ܡH[y/n]");
                input_to("ready_cleanup", obs);
        }
        else return notify_fail("�S���w�ƻs�X�Ӫ��K���ȡC\n");
}

int ready_cleanup(string yn, object obs)
{
        int x;
        if( strlen(yn) < 1 || yn[0] != 'y' )
                return notify_fail("�����M���C\n");
        for(x=0;x<sizeof(obs);x++)
                destruct(obs);
        write(HIR"�w�R�� "+x+" �ӫK���ȡC\n"NOR);
        return 1;
}

int do_checkup(string arg)
{
        object *obs;
        int sw, ob_liz, tmp;
        string out= "";

	if( ob_liz = sizeof(obs=children(__DIR__"3n_easy.c")) )
                out = sprintf("�{�b�� %d �i�K���ȡC\n");

        if( sscanf(arg, "%d", sw) != 1 || sw == 0 )
                if( ob_liz > 1 )
                        for(tmp=0;tmp<ob_liz;tmp++)
                                out += sprintf("��%-2d�i => %s", tmp+1, base_name(environment(obs[tmp])));
        else if( ob_liz > 1 )
                        for(tmp=0;tmp<ob_liz;tmp++)
                                out += sprintf("��%-2d�i => %s\n�@�@�@�@���e�G%s\n",
                                        tmp+1,
                                        base_name(environment(obs[tmp])),
                                        obs[tmp]->long());
        this_player()->start_more(out);
        return 1;
}

int query_autoload() { return 1; }
