#include <ansi.h> 
#include <armor.h>  

inherit NECK; 
void create()
{
        set_name(HIG"�Ĥ�"HIR"�Z�g"NOR ,({ "eouwang woojin","fwoojin" }) );
        set("long",@LONG

 LONG
);
        set_weight(4000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "��");
                set("value",5000);
        } 
    setup();}
switch(random(3))
        {
        case 0;        
                set("armor_prop/bar",1);
                set("armor_prop/str",-2);
        break;
        case 1;
                set("armor_prop/bar",2);
                set("armor_prop/str",-4);
        break; 
        case 2;
                set("armor_prop/dodge",20);
        break;
        case 3;
                set("armor_prop/parry",20);
        beark;
        case 4;
                set("armor_prop/unarmed",20);
        break; 
        case 5;
               set("armor_prop/sword",20);
        break;  
        case 6;
               set("armor_prop/dagger",20);
        break; 
        case 7;
               set("armor_prop/blade",20);
        break; 
        case 8;
                set("armor_prop/fork",20);
        break;
}
