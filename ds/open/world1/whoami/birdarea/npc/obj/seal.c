#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�l���",({"summon seal","seal","_SUMMON_SEAL_"}) );
        set("long",@LONG 
�@�i�Ψӥl��ʦL���~���šE�o�ŧG���F�K�K�³ª���r�A�A��
�Ӭݥh�o�]�ݤ��X�Ӳz�ҵM�ӡE�A�`�N��F�o�Ū��I�����G�g��
�A���x����r�G
             �ʡE�E�E�H���E�E�E
                                  �᭱���N����]�S���F�E         
LONG);
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�i");
                set("value",0);
        }
        setup();
}

