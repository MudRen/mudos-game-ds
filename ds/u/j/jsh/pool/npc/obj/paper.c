#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("���֯�",({"paper"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long",
               HIY"�@�i�ƶ������֯ȡA�W���g�۱K�K�³ª��r�A�W���g ==>\n"
               "�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n"
               "�x�@�@���ߧA�I�I�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�x\n"
               "�x�@�@�@�@�@�@�@�]���A���F�o�i�ȡC�@�@�@�@�@�@�@�x\n"
               "�x�@�@�@�@�@�@�@�ҥH�A�i�H�򳽦Ѥj�D�ԡC�@�@�@�@�@�x\n"
               "�x�@�@�@�@�@�@�@�@�@�@�@�@�@                      �x\n"
               "�x�@�@�@�C���]�p�̡G�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�x\n"
               "�x�@�@�@�@�@�@�@�@�@���Ѥj�@�@�@�@�@�@�@�@�@�@�@�@�x\n"
               "�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n"NOR 
);
             }
        set("value", 500);
        set_weight(100);     
        setup();
}

