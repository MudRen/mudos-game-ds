#include <ansi.h>
inherit NPC;
void create()
{
set_name( "���X���E�ڼw���d", ({ "Lormans Badurleica","mayor","lormans","badurleica","lormans badurleica" }) );
        set("long","(Lormans Badurleica, The Mayor Of Almond Village)\n"
"�L�O�R�����������A���M�L�w�g���~���F�A���O���ؤ������M�o�X�~�~\n"
"�����C�L���g�O�@�W�^�i���Ԥh�A�b�L����j���U�Q���Ъ����c���p��\n"
"�ơC�L���ȪZ�����W�A�b���z�W�]�����Z���B�C�G�Q�h�~�e�L�]�l���@\n"
"�W�y�`�c�{��g���a�A�S�]���˼Ȧ�U�ӡC�Q�h�~��A�A�׸g�L�o�̡A\n"
"����o�̤H�������P�ʦb�R�����w�~�A�����F��L�M�q���ͬ��C���[��\n"
"�����f���A�����N�@�P���|�L��ɲ��H�A���������������C\n"
           );
        set("level",32);
        set("age",55);
        set("title",HIR"�����@"HIG"�Ԥh"NOR);
        set("gender","�k��");
        set("race","�H��");

        set("addition_armor",99);

        setup();

        carry_object(__DIR__"wp/heroaxe")->wield();
}
