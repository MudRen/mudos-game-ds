#include <weapon.h>

inherit GUN;

void create()
{
  set_name("���b��",({"fire gun","gun"}));
        set("long","�o�O�@��j�������b���A�@���u��˶�@�o�l�j�C\n");
        set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",380);
                set("rigidity",500);    //�s�W: �w��
                set("material","iron");
        }

        set("wield_msg","$N�q�I�W���X�@��$n, �ñN$n���O�I�˸m�Ѷ}�C\n");
        set("unwield_msg", "$N�N�⤤��$n�O�I�˸m����, �æ��W�I�C\n");
        set("bullet_type","left_gun");     //�i�Τl�u����
        set("max_load",1);                 //�̤j�˶�q
        init_gun(10); 
        setup();
}

