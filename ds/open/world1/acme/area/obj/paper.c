#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("��", ({ "paper" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("long",
               "�o�Ȥw�x���A�w�۷�}��A�j�j�i���W�Y�X���r�G\n\n"
               HIR"�K�K�K�K���K���N�����K��K�K�é󦹡K�K�A�K�K�K\n"
               "�խߡK�СK���H�K�A��n�K�K�ɡK�D�խߡK�K�K���K\n"
               "�t��K�K\n\n"NOR
               "��A�ݨ�o�̮ɡA�U�b�����ȫo�D���λk�h�A�L�q�o���C\n",
           );
           set("unit","�i");
        }
     setup();
}
