//updated by alickyuen 26/12
#include <ansi.h>      
inherit ITEM;
void create()
{
        set_name(HIW"�����p��"NOR, ({ "crystal diamond","crystal","diamond" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG"�ǻ������J��j�v�N�����M�p�ۿN����V�b�@�_�A���L�W���Ȫ��öQ�_�ۡC\n"NOR);
                set("unit", "��");
                set("material","diamond");
set("value",500);
// set("no_buy",1);    pig shengsan�ˤ��n
        }
}