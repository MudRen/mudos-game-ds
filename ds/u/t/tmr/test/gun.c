#include <weapon.h>

inherit GUN;

void create()
{
        set_name("������j",({"left gun","gun"}));
        set("long","�o�O�@��p����������j�A�@����˶񤻵o�l�j�C\n");
        set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",380);
                set("rigidity",500);    //�s�W: �w��
                set("material","iron");
        }

        set("wield_msg","$N�q�f�U�̮��X�@��$n, �ñN$n���O�I�˸m�Ѷ}�C\n");
        set("unwield_msg", "$N�N�⤤��$n�O�I�˸m����, �é�J�f�U���C\n");
        set("bullet_type","left_gun");     //�i�Τl�u����
        set("max_load",6);                 //�̤j�˶�q
        init_gun(10); 
        setup();
}

