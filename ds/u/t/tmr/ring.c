#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name(HIW "����g�p��" NOR,({"tiffany ring","ring"}) );
        set("long",@LONG
�o�OTiffany�����Ū������p�١A�ϥΤ����`���]�p�A�N�Q�J���p���^�b
�����W�A�̤j���׳]�aŨ���X�F�p�ۡA�ϱo���~�o�H������g�C�o�T���Q
������g�p�١A�H�x�F Tmr �� Rurumi ���ڤ��ܪ��R���C
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�u");       
                set("value",999999999);          
                set("volume", 2);           
                set("material", "gold");   
        }
        setup();
}

int query_autoload() { return 1; }

