#include <weapon.h>
inherit SWORD;
void create(){        set_name("�p���޼C", ({"sexking sword","sword",}) );        
     set_weight(5);        
     if( clonep() )
                set_default_object(__FILE__);
        else {

     set("unit", "�K");                set("long",@LONG            �o�u���L�O�@�K�p���󪺹�޽}�F�CLONG
        );

     set("volume",3);       set("value", 400);        set("material","iron");                set("sword",41);                
      }     
     set("wield_msg", "$N�u�z���v�a�@�n��X�@�K$n���b�⤤�C\n");        set("unwield_msg", "$N�N�⤤��$n�P�@�P��J�f�U�̡C\n");        init_sword(300); 
     setup();
}

