#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{
        set_name(HIY"�u��"NOR,({"clip"}));
        set("long",@long
�O�@�Ӫ��ݻs���u��,�W�g�ۡi��v�j�G�r,�C�@�ռu�����˦�25�o�l�u�C
long
);
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
          set("value", 1000);
        set("material","gold");
        set("amount",25);                //�u�Ķq
        set("bullet/damage",50);        //���ˤO
        set("bullet/unit","�o");        //�u�ĳ��
        set("bullet/name","�l�u");      //�u�ĦW��
        set("type","moon_clip");            //�l�u����
        }
        setup();
}

