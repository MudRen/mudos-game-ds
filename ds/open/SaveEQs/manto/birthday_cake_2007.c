#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIW"����"HIR"����"HIW"��"HIY"���Ԧ�Ĭ"NOR, ({ "tiramisu", "cake" }) );
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
                set("unit", "��");
set("long", "
���Ԧ�Ĭ�ATiramisu�A�b�q�j�Q�娽�A���u�a�ڨ��v���t�q�A

�a�������u�O�����A�٦�"HIR"�R"NOR"�M"HIY"����"NOR"�I�I

�j�f�r�U�h�A���������ַP�q�f���X��������C

�W�����۴X������A����Υ��J�O���e�W�F

"HIM"��"HIW"�ۢ�����"HIY"���p�ͤ�ּ�"HIM"��

"HIC"���p�û��a�ۯ��e"NOR"  --  "HIG"By All Your Friends
"NOR);
        }
set("food_remaining", 8);
        set("heal_hp",1000);  
set("heal_mp",1000);
set("heal_ap",1000);

        setup();
}

int query_autoload() { return 1; }
