#include <armor.h>
inherit HEAD;

void create()
{
        set_name("Arai�w���U",({"arai helmet","helmet"}) );
        set("long",@LONG
�o�O�@���饻�i�f��Arai RR3�w���U�A�W�����Ŧ�������mø�A�٦�
���Ƥ��֪��q��աA���ϥΪ̤��|�P����󪺤��A�C
LONG);
        set_weight(3520);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","plastic");
                set("unit", "��");
                set("limit_level",30);
        }
        set("armor_prop/armor",14);
        setup();
        set("value",25000);
        set("volume", 4);
}
int query_autoload() { return 1; }
