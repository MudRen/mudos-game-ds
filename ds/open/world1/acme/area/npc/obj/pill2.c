#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(MAG "���P��" NOR , ({ "purple star pill", "pill" }));
        set("long","�o�O�@���x�۵��𪺤p���ġA���۴������@�ΡA�ΰ_�k�N�S�O�_�l�C\n");
        set("weight", 200);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "��");
              set("value", 500);
           set("heal_mp",150);
              set("food_remaining", 1);
        }
        setup();
}
