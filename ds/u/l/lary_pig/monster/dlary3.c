#include <ansi.h>
inherit NPC;
void create() {
   set_name(HIW+"�]�C��"+NOR, ({"devil_god","god"}});
   set("long",@Long
�A�u���L�O��L�@���A�M�ӧA��ӤH�o�p�P���J�õL��ɪ��·t�`�W
�A���b�A���e���A�̵M�O���e����֦~�A�����ɥL���W�Ҵ��o�X�Ӫ�
��աA�o�����{�r��Ѧa�U�����W�A�N�b���ɡA�L���Y��V�A�A�b�L
�������z�S�X�G�u���ơB�����B�����B�J�ˡv���h�د����A���ɧA�}
�l���I�ᮬ�A�����D�L�u�����O���d�~�e�A�H�@�v���O�N�ѡB�]���
������L�����A�æP�ɾ֦��ѯ��M�c�]��ط��ݤO�q���]�C�����ܡA
�N�����ӨӻP�L���Ī��C
Long
     );
   set("level",10);
   set_living_name("devilgod");
   set("combat_exp", 10000000);
   set("give_exp", 100000000);
   set("chat_chance",10);
   set("chat_msg",({
       "�]�C���H�N�檺�إ����F�A�@���C\n",
       "�]�C�����L������ۧA�C\n",
            }));
}

void die()
{
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) return;

        message("system",
                HIR "\n\n�Ať��@�n�a�ۼ���B�宣�B�P���~�몺�H���n�T����ӤѪšC\n\n"
                HIW "�V�Ѱ���" HIR "�R�צa�q�ۡR�i�c��" + ob->name(1) + "�M�ڤ@�w�|����������\n\n"
                        "�M��@�D�¦���K�I�S�۽ĤW���ݡM�j�a�S��_�F���R�C\n\n" NOR,
                users() );
        destruct(this_object());
}
