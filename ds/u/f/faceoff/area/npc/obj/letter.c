#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�⥾", ({ "letter", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                 set("long",@LONG
�A�ݨ��W���g��:
       �P�۷R�������Ʃx:
	�̥S�̪��h�𥿦b���C, �ӧڭ̮I��b���F�q��
	�����Ʈv�����������S�̤w�g�Q�Z�l�̵o�{�F.
	�p���̫�ɨ�w�g���, ���@�H�Ҧ��ڪ��x����
	�X�j���Ұꪺ����, �ШD�ߨ�o�L.
				         ���۪��L�ǧJ.
LONG
    );
                }
        setup();
}
