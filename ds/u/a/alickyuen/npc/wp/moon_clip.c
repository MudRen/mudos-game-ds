#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{
set_name(HIY"�u��"NOR,({"moon_clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�O�@�Ӫ��ݻs���u��,�W�g�ۡi��v�j�G�r,\n
          �C�@�ռu�����˦�25�o�l�u�C\n");
        }
set("value", 30000);
set_weight(1220);
set("amount",25);                //�u�Ķq
set("bullet/damage",100);        //���ˤO
set("bullet/unit","�o");        //�u�ĳ��
set("bullet/name","�l�u");      //�u�ĦW��
set("type","moon_clip");            //�l�u����
setup();
}
