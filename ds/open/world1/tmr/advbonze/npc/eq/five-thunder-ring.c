#include <armor.h>
#include <ansi.h> 
inherit FINGER;

void create()
{
        set_name(HIC"���p�g������"NOR,({"five-thunder ring","ring"}) );
        set("long",@LONG
���p�O�D�йp�k�`�Τ���A���k���@�A�Ϋ����B��B���B���B�g����
���p�F�Ϋ��ѹp�B���p�B�a�p�B���p�B���p�F�Τꭷ�p�B���p�B���p�B�Z
�p�B�q�p�F�Τ�ѹp�B�a�p�B���p�B���p�B���p�F�S���p�j�B�p�G�B�p�T
�B�p�|�B�p�������C�@��h�H�e�C�Ĥ@�ج��D�A�פ���ۥͬ۫g�A������
�ʡA�_�o���p�A�G������B��B���B���B�g�ү�o�p�A�O�פ��p�C���p�g
�����١A�O�l�o�ջ����p���g����ѤW���L�H�C�ǦC�s�u���P�I���O����
�p�A�ӻP���P���Y���j�C
LONG
);
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("volume",3);
                set("unit","�u");
                set("value", 15000);
        }
        set("armor_prop/armor", 5);
        set("armor_prop/bio",1);
        set("armor_prop/con", 1);
        set("armor_prop/dex", 1);
        set("armor_prop/sou",-1);
        setup();
}

