
#include <ansi.h>
inherit __DIR__"boat.c";

void create()
{
    set_name(HIG "���Y�N�i����" NOR, ({ "pudu boat","boat" }) );
    set_weight(600);
        set("long",@LONG
����O�����`����̭��n�������A�A�i�H�b����W��m���~�έ���A
���m���h�����~����A�N���Ӫe��a�a�A�I�N(burn)����i����
��A�H����������t����C
���Y�N�i����W���Ŷ�����j�A�i�H��m�T�d�󪫫~�C

�A�i�H�ϥΡuinspect�v���O���˵�����W�w�g��F�h�֪F��C
�A�i�H���u help �����`�v�����ԲӪ���T�C
LONG
);
    set_max_capacity(3000);
    set_max_encumbrance(3000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value", 100);
    }
    setup();
}

