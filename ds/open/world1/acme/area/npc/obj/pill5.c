#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIW "�ٻ" NOR , ({ "resurrect pill", "pill" }));
        set("long","�o�O�@���ʦ~���o�@���������A�s�������H�Y�F�X���ɶ��K\n"
                   "�ण���B���`�H����ءC\n");
        set("weight", 200);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "��");
              set("value", 1750);
           set("heal_hp",250);
           set("heal_mp",150);
           set("help_ap",150);
              set("food_remaining", 1);
        }
        setup();
}
