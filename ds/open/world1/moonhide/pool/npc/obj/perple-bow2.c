#include <weapon.h>
#include <ansi.h>
inherit GUN; 
void create()
{
set_name("���שw���}",({"purple-bow","bow"}));
set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�~���שw���C��A�ܹFù�S���y�@���|�@�L�����}�A�D�O���ۤQ�U
�j�s���F�����һs�C 
LONG);
                set("unit", "��");
                set("rigidity",200);    
                set("material","gold");
                set("limit_int",30);
                set("limit_dex",40);
                set("limit_str",35); 
        }
        set("bullet_type","small");     
        set("max_load",3);              
        init_gun(40);   
        setup();
        set("value",20000); 
}

