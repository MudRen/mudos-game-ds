#include <weapon.h>

inherit GUN;
void create()
{
set_name("HANS�۰ʤ�j",({"hand gun","gun"}));
set("long","�o�O�@��p�����g��(shoot)�Z��, �@���i�H�˶�(reload)12�o�l�u�C\n");
set_weight(4600);
        if( clonep() )
     set_default_object(__FILE__); 
     else {
                set("unit","��");
                set("value",1000);
                set("rigidity",1000);
                set("material","iron");
                set("limit_str",20);
          set("wield_msg","$N�q�f�U�̮��X�@��$n, �ñN$n���O�I�˸m�Ѷ}�C\n");
          set("unwield_msg", "$N�N�⤤��$n�O�I�˸m����, ���^�j�a���C\n");  
          set("bullet_type","small");
          set("max_load",12);
          init_gun(13); 
          setup();
}  
}
