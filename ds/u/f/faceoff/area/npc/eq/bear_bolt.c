#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{

set_name(HIR"�����u�s"NOR,({"bear bolt","bolt"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�@���b�Y���������n�b, ���p����, �i�H�N�b���r�J�˥Ҥ���.\n");
        }
set("value", 80);
set_weight(1200);
set("amount",1);                //�u�Ķq
set("bullet/damage",20);        //���ˤO
set("bullet/unit","��");        //�u�ĳ��
set("bullet/name","���b");      //�u�ĦW��
set("type","small");            //�l�u����
setup();
}
