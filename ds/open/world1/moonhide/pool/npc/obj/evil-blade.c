#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIR"�]�@�M"NOR,({"evil-blade","blade","evil"}));

        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIC"\n\t\t�W�j���L�ۻs�y�A�[�W�c�]��G���y�X���]�ʤ��@�C\n"NOR);
                set("volume",2);
                set("unit", "��");
                set("value",10000);
                set("material","silver");
        }
                set("limit_skill",50);
                set("limit_lv",25);
                set("limit_str",30);
                set("limit_dex",30);
        init_blade(50);
                       setup();
}

