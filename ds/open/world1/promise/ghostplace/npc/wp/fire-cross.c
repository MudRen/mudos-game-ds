#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIR"(���N)"HIY"��"NOR+YEL"�v"HIW"�Q�r"NOR"�["NOR,({"fire cross","fire","cross"}));

        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIG"\n\t��v�t�M�A�b���ٱ��ۤ@�ӡu"HIY"�Q"HIG"�v�r�[�Y��A��������ηN�C\n"NOR);
                set("volume",2);
                set("unit", "��");
                set("value",4500);
                set("limit_skill",40);
                set("material","gold");
                set("limit_lv",30);
                set("limit_str",30);
                set("limit_dex",30); 
                set("limit_con",30);
                set("limit_int",30);
        }
        init_blade(51);
                       setup();
}

